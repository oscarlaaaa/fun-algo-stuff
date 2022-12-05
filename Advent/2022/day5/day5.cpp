#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <bitset>
using namespace std;

string solve(vector<vector<int>> &input) {
    /*
        simulate each step and return the top of each stack after
    */
    vector<vector<char>> crates = {{},
        {'D', 'L', 'J', 'R', 'V', 'G', 'F'},
        {'T','P','M','B','V','H','J','S'},
        {'V','H','M','F','D','G','P','C'},
        {'M','D','P','N','G','Q'},
        {'J','L','H','N','F'},
        {'N','F','V','Q','D','G','T','Z'},
        {'F','D','B','L'},
        {'M','J','B','S','V','D','N'},
        {'G','L','D'}
    };
    for (vector<int> move : input) {
        int num = move[0], from = move[1], to = move[2];
        for (int i=0; i<num; i++) {
            if (crates[from].empty()) 
                break;
            crates[to].push_back(crates[from].back());
            crates[from].pop_back();
        }
    }
    string output = "";
    for (vector<char> stack : crates) {
        if (stack.empty()) continue;
        output += stack.back();
    }
    return output;
}

string solve2(vector<vector<int>> &input) {
    /*
        pop it onto a different stack, then pop it back in the same order
    */
   vector<vector<char>> crates = {{},
        {'D', 'L', 'J', 'R', 'V', 'G', 'F'},
        {'T','P','M','B','V','H','J','S'},
        {'V','H','M','F','D','G','P','C'},
        {'M','D','P','N','G','Q'},
        {'J','L','H','N','F'},
        {'N','F','V','Q','D','G','T','Z'},
        {'F','D','B','L'},
        {'M','J','B','S','V','D','N'},
        {'G','L','D'}
    };
    for (vector<int> move : input) {
        int num = move[0], from = move[1], to = move[2];
        vector<char> holder;
        for (int i=0; i<num; i++) {
            if (crates[from].empty()) 
                break;
            holder.push_back(crates[from].back());
            crates[from].pop_back();
        }
        while (!holder.empty()) {
            crates[to].push_back(holder.back());
            holder.pop_back();
        }
    }
    string output = "";
    for (vector<char> stack : crates) {
        if (stack.empty()) continue;
        output += stack.back();
    }
    return output;
}

int main() {
    /*
        [S] [C]         [Z]            
    [F] [J] [P]         [T]     [N]    
    [G] [H] [G] [Q]     [G]     [D]    
    [V] [V] [D] [G] [F] [D]     [V]    
    [R] [B] [F] [N] [N] [Q] [L] [S]    
    [J] [M] [M] [P] [H] [V] [B] [B] [D]
    [L] [P] [H] [D] [L] [F] [D] [J] [L]
    [D] [T] [V] [M] [J] [N] [F] [M] [G]
    1   2   3   4   5   6   7   8   9 

    */
    freopen("input.txt", "r", stdin);
    vector<vector<int>> input;
    string a, count, b, from, c, to;
    for (int i=0; i<504; i++) {
        cin >> a >> count >> b >> from >> c >> to;
        input.push_back({stoi(count), stoi(from), stoi(to)});
    }
    string output = solve2(input);
    cout << output;
    return 0;
}
