#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <bitset>
using namespace std;

int solve(vector<vector<pair<int, int>>> &input) {
    /*
        Simply look through the pairs for one that wraps completely around the other.
    */
    int count = 0;
    for (vector<pair<int, int>> x : input) {
        auto [L1, R1] = x[0];
        auto [L2, R2] = x[1];
        if ((L1 <= L2 && R2 <= R1) || (L2 <= L1 && R1 <= R2)) count++;
    }
    return count;
}

int solve2(vector<vector<pair<int, int>>> &input) {
    /*
        Intervals overlap if the max of the left bound is greater than the min of the right bounds.
    */
    int count = 0;
    for (vector<pair<int, int>> x : input) {
        auto [L1, R1] = x[0];
        auto [L2, R2] = x[1];
        if (max(L1, L2) <= min(R1, R2)) count++;
    }
    return count;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<vector<pair<int, int>>> input;
    string line;
    for (int i=0; i<1000; i++) {
        cin >> line;
        
        int center = line.find(",");
        string l = line.substr(0, center), r = line.substr(center+1);
        vector<pair<int, int>> group;

        center = l.find("-");
        group.push_back({stoi(l.substr(0, center)), stoi(l.substr(center+1))});
        center = r.find("-");
        group.push_back({stoi(r.substr(0, center)), stoi(r.substr(center+1))});
        input.push_back(group);
    }

    cout << solve2(input);
    return 0;
}
