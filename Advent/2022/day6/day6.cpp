#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <bitset>
using namespace std;

int solve(string &input) {
    /*
        count number of chars within sliding window of size 4
    */
    unordered_map<char, int> counts;
    for (int i=0; i<input.size(); i++) {
        if (!counts.count(input[i])) 
            counts[input[i]] = 0;

        counts[input[i]]++;
        if (i >= 4) {
            counts[input[i-4]]--;
            if (counts[input[i-4]] == 0) 
                counts.erase(input[i-4]);
        }

        if (counts.size() == 4) 
            return i+1;
    }
    return -1;
}

int solve2(string &input) {
    /*
        count number of chars within sliding window of size 14
    */    
    unordered_map<char, int> counts;
    for (int i=0; i<input.size(); i++) {
        if (!counts.count(input[i])) 
            counts[input[i]] = 0;
        
        counts[input[i]]++;
        if (i >= 14) {
            counts[input[i-14]]--;
            if (counts[input[i-14]] == 0) 
                counts.erase(input[i-14]);
        }

        if (counts.size() == 14) 
            return i+1;
    }
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    string input;
    cin >> input;
    cout << "part 1: " << solve1(input) << endl;
    cout << "part 2: " << solve2(input) << endl;
    return 0;
}
