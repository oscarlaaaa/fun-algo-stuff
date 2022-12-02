#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <queue>
#include <unordered_map>
using namespace std;

int solve(vector<vector<int>> &input) {
    /*
        input: list of rps matches
        output: total score following instructions
        
        notes:
        - A for Rock, B for Paper, and C for Scissors
        - X for Rock, Y for Paper, and Z for Scissors.
        - The score for the shape you selected (1 for Rock, 2 for Paper, and 3 for Scissors) 
        - ...plus the score for the outcome of the round (0 if you lost, 3 if the round was a draw, and 6 if you won).
        approach:
        - sum up each list
        - track the largest sum and return at the end
    */
    int score = 0;
    for (vector<int> match : input) {
        int opponent = match[0], me = match[1];
        score += me + 1;
        if (me < opponent) me += 3;
        if (me - opponent == 0) {
            score += 3;
        } else if (me - opponent == 1) {
            score += 6;
        } 
    }
    return score;
}

int solve2(vector<vector<int>> &input) {
    /*
        input: list of rps matches
        output: total score following instructions
        
        notes:
        - A for Rock, B for Paper, and C for Scissors
        - X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win.
        - The score for the shape you selected (1 for Rock, 2 for Paper, and 3 for Scissors) 
        - ...plus the score for the outcome of the round (0 if you lost, 3 if the round was a draw, and 6 if you won).
        approach:
        - sum up each list
        - track the largest sum and return at the end
    */
    int score = 0;
    for (vector<int> match : input) {
        int opponent = match[0], me = match[1];
        if (me == 0) {
            score += (opponent + 2)%3 + 1;
        } else if (me == 1) {
            score += 3 + opponent + 1;
        } else {
            score += 6 + (opponent + 1)%3 + 1;
        }
    }
    return score;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<vector<int>> input;
    unordered_map<char, int> convert;
    convert['A'] = 0;
    convert['B'] = 1;
    convert['C'] = 2;
    convert['X'] = 0;
    convert['Y'] = 1;
    convert['Z'] = 2;
    char opp, me;
    for (int i=0; i<2500; i++) {
        cin >> opp >> me;
        input.push_back({convert[opp], convert[me]});
    }

    cout << solve2(input);
    return 0;
}
