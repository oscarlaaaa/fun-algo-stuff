// 2022-12-14 (tabulation DP)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*
            input: 2 strings text1 and text2
            output: length of longest common subsequence between the two

            notes:
            - the two strings may have different lengths (no guarantee which)
            - probably DP (since you can break this up into smaller subproblems)
            - 2d array?
                - if text1[i] == text2[j] then arr[i+1][j+1] = current + 1?
                - take the max of the arr[i][j-1] and the new value to get the number
                  of letters in the subsequence at that spot

            approach:
            - initialize 2d array with length m+1 and n+1
                - need +1 as if we go the above route, we need an extra row/col to hold the
                  last matches
            - for each index 0<=i<m and 0<=j<n
                - assign arr[i+1][j] and arr[i][j+1] if curr is larger than their values
                    - this is so that we don't lose track of what our current longest substring is
                      even if we don't have immediate matches while we iterate
                - if characters match, then arr[i+1][j+1] = arr[i][j]+1
            - return the value at arr[m][n]
        */
        int m = text1.length(), n = text2.length();
        vector<vector<int>> longest(m+1, vector<int>(n+1, 0));
        for (int i=0; i<m+1; i++) {
            for (int j=0; j<n+1; j++) {
                if (i < m && j < n && text1[i] == text2[j])
                    longest[i+1][j+1] = longest[i][j]+1;
                if (i < m)
                    longest[i+1][j] = max(longest[i][j], longest[i+1][j]);
                if (j < n)
                    longest[i][j+1] = max(longest[i][j], longest[i][j+1]);
            }
        }
        return longest[m][n];
    }
};