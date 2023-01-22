// 2023-01-22 (two-pointer + backtracking)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        /*
            input: a string 
            output: all possible palindrome partitions of s

            notes:
            - needs to line up; looks kinda like backtracking, but detecting palindromes
              will be expensive unless we pre-compute it
            - probably find palindromes -> store in a way that makes grouping them easy
              -> return the groupings

            approach:
            - find palindromes by taking groups of 1, then 2 characters and fanning outwards
                - use a queue to process them
            - for each palindrome found, store in a vector of vector of strings where the left-most
              position is the index to store the palindrome
                - vector[i] = palindromes that start at index i
            - iterate through the palindromes using a queue, and group them
                - start at 0, and for each palindrome find the next palindromes at vector[i+palindrome.length()]
            - return groupings

            analysis:
            - time: O(2^n) where n=length of string
            - space: O(n^2) where n=length of string
        */
        int n = s.length();

        // find and group palindromes according to start index
        vector<vector<string>> groupings(n);
        deque<pair<int, int>> palins;
        for (int i=0; i<n; i++) {
            palins.push_back({i,i});
            if (i >= 1)
                palins.push_back({i-1, i});
        }
        while (!palins.empty()) {
            auto [start, end] = palins.front();
            palins.pop_front();
            if (s[start] != s[end]) 
                continue;
            
            groupings[start].push_back(s.substr(start, end-start+1));
            if (start-1 >= 0 && end+1 < n)
                palins.push_back({start-1, end+1});            
        }

        // find all combinations of palindromes with indices that line up
        vector<vector<string>> output;
        vector<string> current;
        findPartitions(groupings, 0, current, output);
        return output;
    }

    void findPartitions(vector<vector<string>>& groupings, int pos, vector<string>& current, vector<vector<string>>& output) {
        if (pos == groupings.size()) {
            output.push_back(vector<string>(current.begin(), current.end()));
            return;
        }

        for (string& s : groupings[pos]) {
            current.push_back(s);
            findPartitions(groupings, pos+s.length(), current, output);
            current.pop_back();
        }
    }
};