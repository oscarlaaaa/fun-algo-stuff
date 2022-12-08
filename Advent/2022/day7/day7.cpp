#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

long long popAndAggregate(deque<pair<string, long long>>& path) {
    auto& [folder, size] = path.back();
    path.pop_back();
    path.back().second += size;
    return size;
}

long long solve(vector<vector<string>> &input) {
    /*
        Use a stack to hold the path and the current folder. Whenever we "cd .." or 
        "cd /", pop from the stack and add the size to the next top of the stack. If
        we pop off a directory with size <= 100000, add it to our total.
    */
    long long total = 0;
    deque<pair<string, long long>> path = {{"/", 0}};
    for (vector<string> cmd : input) {
        if (cmd[0] == "$") {
            if (cmd[1] == "cd") {
                // if we're going back, pop current val from stack and add val to previous one
                if (cmd[2] == "..") { 
                    int size = popAndAggregate(path);
                    if (size <= 100000) 
                        total += size;
                } else if (cmd[2] == "/") {
                    while (path.size() > 1) {
                        int size = popAndAggregate(path);
                        if (size <= 100000) 
                            total += size;
                    }
                } else {
                // if we're going forward, put a new folder onto the stack
                    path.push_back({cmd[2], 0});
                }
            }
        } else {
            if (cmd[0] != "dir") 
                path.back().second += stoi(cmd[0]);
        }
    }

    while (path.size() > 1) {
        int size = popAndAggregate(path);
        if (size <= 100000) 
            total += size;
    }

    if (path.back().second <= 100000) 
        total += path.back().second;

    return total;
}

long long solve2(vector<vector<string>> &input) {
    /*
        Same as part 1 where we utilize the stack-popping mechanism, except
        this time we use it to size up the entire directory. We also put every folder size
        into a set and iterate through it, taking the first one that gives us enough space
        for our update.
    */    
    long long MAX_SPACE_ALLOWED = 40000000;
    vector<long long> allSizes;
    deque<pair<string, long long>> path = {{"/", 0}};
    for (vector<string> cmd : input) {
        if (cmd[0] == "$") {
            if (cmd[1] == "cd") {
                // if we're going back, pop current val from stack and add val to previous one
                if (cmd[2] == "..") { 
                    allSizes.push_back(popAndAggregate(path));
                } else if (cmd[2] == "/") {
                    while (path.size() > 1) {
                        allSizes.push_back(popAndAggregate(path));
                    }
                } else {
                // if we're going forward, put a new folder onto the stack
                    path.push_back({cmd[2], 0});
                }
            }
        } else {
            if (cmd[0] != "dir") 
                path.back().second += stoi(cmd[0]);
        }
    }
    // Pop off the rest of our stack
    while (path.size() > 1) {
        allSizes.push_back(popAndAggregate(path));
    }
    allSizes.push_back(path.back().second);

    // Get how much we need to remove by taking total size - total size we're allowed to take up.
    long long needed = path.back().second - MAX_SPACE_ALLOWED, smallest = INT_MAX;
    for (auto itr=allSizes.begin(); itr != allSizes.end(); itr++) {
        if (*itr >= needed && *itr < smallest) 
            smallest = *itr;
    }
    return smallest;
}

vector<string> parseLine(string s) {
    vector<string> output = {""};
    for (char& c : s) {
        if (isspace(c)) {
            output.push_back("");
        } else {
            output.back() += c;
        }
    }
    return output;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<vector<string>> input;
    string s;
    unordered_set<string> repeats;
    while (getline(cin, s)) {
        if (repeats.count(s)) {
            cout << s << " IS A REPEAT!!!!!" << endl;
        }
        input.push_back(parseLine(s));
    }
    cout << "part 1: " << solve(input) << endl;
    cout << "part 2: " << solve2(input) << endl;
    return 0;
}

