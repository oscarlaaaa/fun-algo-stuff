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

bool tooFar(int Hx, int Hy, int Tx, int Ty) {
    return max(abs(Hx - Tx), abs(Hy - Ty)) >= 2;
}

int solve(vector<pair<string, int>> &input) {
    /*
        count the number of positions visited by the tail
    */
    unordered_map<int, unordered_set<int>> tail_positions = {{0, {0}}};
    unordered_map<string, pair<int, int>> movement = {{"R", {0,1}}, {"U", {-1,0}}, {"D", {1,0}}, {"L", {0,-1}}};
    int Hx = 0, Hy = 0, Tx = 0, Ty = 0;
    for (auto& [d, steps] : input) {
        auto& [moveX, moveY] = movement[d];
        for (int i=0; i<steps; i++) {
            if (tooFar(Hx+moveX, Hy+moveY, Tx, Ty)) {
                Tx = Hx;
                Ty = Hy;
            }
            Hx += moveX;
            Hy += moveY;
            tail_positions[Tx].insert(Ty);
        }
    }
    int total = 0;
    for (auto itr=tail_positions.begin(); itr != tail_positions.end(); itr++) {
        auto [pos, vals] = *itr;
        total += vals.size();
    }
    return total;
}

void printLayout(vector<int>& x, vector<int>& y) {
    vector<vector<char>> z(30, vector<char>(30, '.'));
    for (int i=9; i>=0; i--) {
        z[x[i]][y[i]] = i == 0 ? 'H' : '0' + i;
    }

    for (int i=0; i<30; i++) {
        cout << endl;
        for (int j=0; j<30; j++) {
            cout << z[i][j];
        }
    }
    cout << endl;
}

int solve2(vector<pair<string, int>> &input) {
    /*
        count the number of positions visited by the tail
    */
    unordered_map<int, unordered_set<int>> tail_positions = {{15, {11}}};
    unordered_map<string, pair<int, int>> movement = {{"R", {0,1}}, {"U", {-1,0}}, {"D", {1,0}}, {"L", {0,-1}}};
    vector<int> x(10, 15), y(10, 11);
    for (auto& [d, steps] : input) {
        auto& [moveX, moveY] = movement[d];
        for (int i=0; i<steps; i++) {
            x[0] += moveX;
            y[0] += moveY;
            for (int i=1; i<10; i++) {
                if (tooFar(x[i-1], y[i-1], x[i], y[i])) {
                    if (x[i-1] != x[i] && y[i-1] != y[i]) {
                        x[i] += x[i-1] > x[i] ? 1 : -1;
                        y[i] += y[i-1] > y[i] ? 1 : -1;
                    } else {
                        if (x[i-1] == x[i])
                            y[i] += y[i-1] > y[i] ? 1 : -1;
                        else if (y[i-1] == y[i])
                            x[i] += x[i-1] > x[i] ? 1 : -1;
                    }
                } 
            }
            tail_positions[x[9]].insert(y[9]);
        }
    }
    int total = 0;
    for (auto itr=tail_positions.begin(); itr != tail_positions.end(); itr++) {
        auto [pos, vals] = *itr;
        total += vals.size();
    }
    return total;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<pair<string, int>> input;
    string direction, steps;
    for (int i=0; i<2000; i++) {
        cin >> direction >> steps;
        input.push_back({direction, stoi(steps)});
    }
    cout << "part 1: " << solve(input) << endl;
    cout << "part 2: " << solve2(input) << endl;
    return 0;
}

