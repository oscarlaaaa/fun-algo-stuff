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


int solve(vector<vector<int>> &input) {
    /*
        Traverse the grid from left->right, right->left, top->bottom, bottom->top and see
        if it's the tallest encountered thus far.
    */
    int m = input.size(), n = input[0].size();
    vector<vector<bool>> visible(m, vector<bool>(n, 0));

    // traverse left->right and right->left at the same time
    for (int i=0; i<m; i++) {
        int largestLeft = -1, largestRight = -1;
        for (int j=0; j<n; j++) {
            if (input[i][j] > largestLeft) {
                visible[i][j] = true;
                largestLeft = input[i][j];
            }

            if (input[i][n-1-j] > largestRight) {
                visible[i][n-1-j] = true;
                largestRight = input[i][n-1-j];
            }
        }
    }

    for (int j=0; j<n; j++) {
        int largestTop = -1, largestBottom = -1;
        for (int i=0; i<m; i++) {
            if (input[i][j] > largestTop) {
                visible[i][j] = true;
                largestTop = input[i][j];
            }

            if (input[m-1-i][j] > largestBottom) {
                visible[m-1-i][j] = true;
                largestBottom = input[m-1-i][j];
            }
        }
    }

    int count = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (visible[i][j]) count++;
        }
    }
    return count;
}

int solve2(vector<vector<int>> &input) {
    /*
        Utilize a monotonic stack (greatest to least) of indices; if we encounter a tree
        that's taller than the top of our stack, we pop off until we hit one >=. 

        You can calculate the distance by getting the current index - the top of the stack's
        (or, if empty, 0) index. We hold the multiplicative values within a vector and perform
        the process in all 4 directions.
    */
    int m = input.size(), n = input[0].size();
    vector<vector<long long>> visible(m, vector<long long>(n, 1));

    // find products of left->right, and right->left concurrently
    for (int i=0; i<m; i++) {
        vector<int> l, r;
        for (int j=0; j<n; j++) {
            while (!l.empty() && input[i][j] > input[i][l.back()]) 
                l.pop_back();
            while (!r.empty() && input[i][n-1-j] > input[i][n-1-r.back()]) 
                r.pop_back();

            visible[i][j] *= l.empty() ? j : j-l.back();
            visible[i][n-1-j] *= r.empty() ? j : j-r.back();

            l.push_back(j);
            r.push_back(j);
        }
    }

    // find products of top->bottom, and bottom->top respectively
    for (int j=0; j<n; j++) {
        vector<int> t, b;
        for (int i=0; i<m; i++) {
            while (!t.empty() && input[i][j] > input[t.back()][j]) 
                t.pop_back();
            while (!b.empty() && input[m-1-i][j] > input[m-1-b.back()][j]) 
                b.pop_back();

            visible[i][j] *= t.empty() ? i : i-t.back();
            visible[m-1-i][j] *= b.empty() ? i : i-b.back();

            t.push_back(i);
            b.push_back(i);
        }
    }

    long long maximum = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            maximum = max(maximum, visible[i][j]);
        }
    }
    return maximum;
}

vector<int> parseLine(string s) {
    vector<int> output;
    for (char& c : s) {
        if (isspace(c)) continue;
        output.push_back(c - '0');
    }
    return output;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<vector<int>> input;
    string s;
    while (getline(cin, s)) {
        input.push_back(parseLine(s));
    }
    cout << "part 1: " << solve(input) << endl;
    cout << "part 2: " << solve2(input) << endl;
    return 0;
}

