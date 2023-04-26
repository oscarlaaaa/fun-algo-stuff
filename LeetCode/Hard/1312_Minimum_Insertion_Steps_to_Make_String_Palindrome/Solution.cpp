// 2023-04-26 (memoization dp)
class Solution {
private:
    vector<vector<int>> memo;
    int findMinInsertions(string& s, int l, int r) {
        if (l >= r)
            return 0;

        if (memo[l][r] != -1)
            return memo[l][r];
        
        int minInsertions = INT_MAX;
        if (s[l] != s[r]) {
            minInsertions = min(minInsertions, 1+findMinInsertions(s, l+1, r));
            minInsertions = min(minInsertions, 1+findMinInsertions(s, l, r-1));
        } else {
            minInsertions = min(minInsertions, findMinInsertions(s, l+1, r-1));
        }
        
        memo[l][r] = minInsertions;
        return minInsertions;
    }
public:
    int minInsertions(string s) {
        /*
        notes:
        - can insert any character into the string at any index
        - minimum number of steps to make s a palindrome
        - seems like it's always length of string - longest palindrome
            - just find longest palindrome first?
            - actually maybe not; we can insert in the middle as well
            - there are also multiple ways to insert and convert into a palindrome
        - maybe 2 pointers and whenever there's a non-match just insert?
            - maybe we need to explore recursion to see if we want to insert on left or right
        - could also do tabulation with nxn grid, start at [0][n-1] and init with int_max
            - iterate from i=[n-1, 0] and j=[0, n]
            - if non-match at [i][j], set [i+1][j] or [i][j-1] as min of [i][j]+1
            - if match, apply min of current to [i+1][j-1]
            - look at all points where i=j AND where we had i=j-1 and find smallest number
        */
        int n = s.length();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        return findMinInsertions(s, 0, n-1);
    }
};

// 2023-04-26 (tabulation)
class Solution {
public:
    int minInsertions(string s) {
        /*
        notes:
        - can insert any character into the string at any index
        - minimum number of steps to make s a palindrome
        - seems like it's always length of string - longest palindrome
            - just find longest palindrome first?
            - actually maybe not; we can insert in the middle as well
            - there are also multiple ways to insert and convert into a palindrome
        - maybe 2 pointers and whenever there's a non-match just insert?
            - maybe we need to explore recursion to see if we want to insert on left or right
        - could also do tabulation with nxn grid, start at [0][n-1] and init with int_max
            - iterate from i=[n-1, 0] and j=[0, n]
            - if non-match at [i][j], set [i+1][j] or [i][j-1] as min of [i][j]+1
            - if match, apply min of current to [i+1][j-1]
            - look at all points where i=j AND where we had i=j-1 and find smallest number
        
        analysis:
        - time = O(n^2) where n=length of s
        - space = O(n^2) where n=length of x
        */
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        memo[0][n-1] = 0;

        int minimum = INT_MAX;
        for (int i=0; i<n; i++) {
            for (int j=n-1; j>=i; j--) {
                // if both pointers have touched already
                if (i >= j-1) {
                    minimum = min(minimum, (s[i] == s[j] ? memo[i][j] : memo[i][j]+1));
                    continue;
                }
                
                // if match, carry current value and move both pointers inwards
                if (s[i] == s[j]) 
                    memo[i+1][j-1] = memo[i][j];
                
                // try inserting for the left or the right character
                memo[i+1][j] = min(memo[i+1][j], 1+memo[i][j]);
                memo[i][j-1] = min(memo[i][j-1], 1+memo[i][j]);
            }
        }

        return minimum;
    }
};