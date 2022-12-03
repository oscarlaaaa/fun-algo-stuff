#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <bitset>
using namespace std;

int getPriority(char c) {
    return (c < 'a' ? c - 'A' + 27 : c - 'a' + 1);
}

int solve(vector<string> &input) {
    /*
        input: list of strings representing items in rucksacks
        output: sum of priorities of items that appear in both compartments

        notes:
        - half of string is compartment 1, other half is compartment 2 
        - a-z is 1-26, A-Z is 27-52

        approach:
        - split each rucksack into 2 compartments
        - utilize a bitset to determine common char
        - if the ascii is < 'a', then priority is char - 'A' + 27
        - otherwise, priority is char - 'a' + 1
        - each common char is added to the output once, so flip bitset off if matched
        - return sum
    */

    int output = 0;
    for (int i=0; i<input.size(); i++) {
        bitset<256> present;
        string sack = input[i];
        int n = sack.length();
        for (int j=0; j<n/2; j++) {
            present[sack[j]] = 1;
        }
        for (int j=n/2; j<n; j++) {
            if (present[sack[j]]) {
                output += getPriority(sack[j]);
                present[sack[j]] = 0;
            }
        }
    }

    return output;   
}

int solve2(vector<string> &input) {
    /*
        input: list of strings representing items in rucksacks
        output: sum of priorities of badges common in groups of 3

        notes:
        - elves are in groups of 3 (3 lines of input per group)
        - badge is the only common value between all 3

        approach:
        - split input into groups of 3
        - take the bitsets of the occurring elements from every rucksack
        - AND the bitset to a parent bitset for each sack
        - in the end, should be left with a single 1 bit that represents the badge
        - add the badge val to the output
    */
    int output = 0;
    for (int i=0; i<input.size(); i+=3) {
        bitset<256> common = bitset<256>().set();
        for (int j=i; j<i+3; j++) {
            bitset<256> sack;
            for (char &c : input[j]) {
                sack[c] = 1;
            }
            common &= sack;
        }

        for (int i=0; i<256; i++) {
            if (common[i]) {
                output += getPriority(i);
            }
        }
    }
    return output;
}

int main() {
    freopen("input.txt", "r", stdin);
    vector<string> input;
    string line;
    for (int i=0; i<300; i++) {
        cin >> line;
        input.push_back(line);
    }

    cout << solve2(input);
    return 0;
}
