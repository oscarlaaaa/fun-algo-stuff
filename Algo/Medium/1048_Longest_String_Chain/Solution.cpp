// 2022-06-18
/**
 * This word is a dynamic programming problem at first glance. How you can
 * determine this is figuring out the fact that if a word's longest string
 * chain is independent of its predecessors (i.e. if the word "abc" has N 
 * length longest string chain, its predecessors "ab" and "bc" will just have
 * N + 1 length longest string chain).
 * 
 * Thus, we approach this problem with a top-down memoization solution, where
 * we check each word with N length against each word with N+1 length to see
 * if they're predecessors, and recurse down if so. Memoizing each word's longest
 * string chain helps us avoid repeated calculations.
 * 
 */
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // organize words by order of length
        vector<vector<string>> wordLengths(17);
        for (string word : words) {
            wordLengths[word.length()].push_back(word);
        }
        
        // store longest string chains for each word
        vector<vector<int>> memo(17);
        for (int i=0; i<17; i++) {
            vector<int> row(wordLengths[i].size(), -1);
            memo[i] = row;
        }
        
        int longest = 0;
        for (int i=1; i<17; i++) {
            for (int j=0; j<wordLengths[i].size(); j++) {
                // only check if we haven't already encountered it, since having the memo for the word be != -1
                // means that we have found the longest for it already
                if (memo[i][j] == -1) {
                    longest = max(longest, findLongestChain(wordLengths, i, j, memo));
                }
            }
        }
        
        return longest;
    }
    
    // size and word represent the current word length, and the index of the word within wordLengths[i]
    int findLongestChain(vector<vector<string>>& wordLengths, int size, int word, vector<vector<int>>& memo) {
        // length limit is 16, so we've reached our goal 
        if (size+1 >= wordLengths.size())
            return 1;
        
        if (memo[size][word] != -1)
            return memo[size][word];
        
        string curWord = wordLengths[size][word];
        int longest = 1;
        for (int i=0; i<wordLengths[size+1].size(); i++) {
            if (isPredecessor(curWord, wordLengths[size+1][i])) {
                longest = max(longest, 1 + findLongestChain(wordLengths, size+1, i, memo));
            }
        }
        memo[size][word] = longest;
        return longest;
    }
    
    bool isPredecessor(string& word1, string& word2) {
        int idx1 = 0, idx2 = 0;
        while (idx1 < word1.length() && idx2 < word2.length()) {
            if (word1[idx1] == word2[idx2]) 
                idx1++;
            idx2++;
        }
        return word1.length() == idx1; // word1 should be completely traversed thru if its a predecessor of word2
    }
    
};