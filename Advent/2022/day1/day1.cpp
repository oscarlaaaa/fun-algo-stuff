#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <queue>
using namespace std;

string trim(const string &s)
{
  auto first = s.find_first_not_of(" \f\n\r\t\v");
  auto last  = s.find_last_not_of (" \f\n\r\t\v");
  return (first == s.npos) ? "" : s.substr( first, last+1 );
}

int solve(vector<vector<int>> &input) {
    /*
        input: 2d list of elves and their calories
        output: greatest total calories for an elf

        approach:
        - sum up each list
        - track the largest sum and return at the end
    */
    int maximum = 0;
    for (vector<int> elf : input) {
        int calories = std::accumulate(elf.begin(), elf.end(), 0);
        maximum = max(maximum, calories);
    }
    return maximum;
}

int solve2(vector<vector<int>> &input) {
    /*
        input: 2d list of elves and their calories
        output: greatest total calories for an elf

        approach:
        - sum up each list
        - track largest 3 calorie counts using a min priority queue
        - return the values left in the pq
    */
    priority_queue<int, vector<int>, greater<int>> largest3;
    for (vector<int> elf : input) {
        int calories = std::accumulate(elf.begin(), elf.end(), 0);
        largest3.push(calories);
        if (largest3.size() > 3)
            largest3.pop();
    }
    
    int total = 0;
    for (int i=0; i<3; i++) {
        total += largest3.top();
        largest3.pop();
    }
    return total;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<vector<int>> input = {{}};
    string temp;
    while (getline(cin, temp)) {
        if (trim(temp).empty()) {
            input.push_back({});
        } else {
            input.back().push_back(stoi(temp));
        }
    }

    cout << solve2(input);
    return 0;
}
