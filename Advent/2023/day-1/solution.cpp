#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <queue>
#include <unordered_map>

using namespace std;

int solve(vector<string> &input) {
    int total = 0;
    for (string& line : input) {
        int lineVal = 0;
        for (int i=0; i<line.length(); i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                int x = line[i] - '0';
                
		        lineVal = (lineVal+x) * 10;
                break;
            }
        }
        for (int i=line.length()-1; i >= 0; i--) {
            if (line[i] >= '0' && line[i] <= '9') {
                int x = line[i]-'0';
                lineVal += x;
		        break;
            }
        }
        total += lineVal;
    }
    return total;
}

int solve2(vector<string> &input) {
    int total = 0;
    unordered_map<string, int> numbers = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},{"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

    for (string& line : input) {
        int lineVal = 0;
        for (int i=0; i<line.length(); i++) {
            bool found = false;
            for (auto [s, v] : numbers) {
                if (line.substr(i, min(line.length()-i, s.length())) == s) {
                    lineVal += v;
                    found = true;
                    break;
                }
            }

            if (found) break;

            if (line[i] >= '0' && line[i] <= '9') {
                int x = line[i] - '0';
		        lineVal += x;
                break;
            }
        }
        cout << lineVal << endl;
        lineVal *= 10;
        for (int i=line.length()-1; i >= 0; i--) {
            bool found = false;
            if (line[i] >= '0' && line[i] <= '9') {
                int x = line[i]-'0';
                lineVal += x;
		        break;
	        }

            for (auto [s, v] : numbers) {
                if (line.substr(i, min(line.length()-i, s.length())) == s) {
                    lineVal += v;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        cout << lineVal<< endl << endl;
        total += lineVal;
    }
    return total;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<string> input;
    string temp;
    while (getline(cin, temp)) {
        input.push_back(temp);
    }

    cout << solve2(input);
    return 0;
}
