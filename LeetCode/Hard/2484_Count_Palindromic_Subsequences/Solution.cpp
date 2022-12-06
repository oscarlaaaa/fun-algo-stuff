// 2022-11-26 (prefix-suffix approach)
class Solution {
public:
    #define ll long long
    int countPalindromes(string s) {
        /*
        input: a string of numerical digits
        output: number of palindromic subsequences possible

        approach:
        - iterate from left to right, keeping track of:
            - the count of each type of digit encountered so far
            - the count of each possible 2-digit encountered so far
        - repeat for right to left
        - iterate through the string, and take the 2-digit counts left-to-right for idx-1,
          and right-to-left for idx+1, where idx represents the middle digit in a length 5 palindrome
            - for each position, add the multiple of the left and right counts of the same 2-digit strings
              to the total
        - return the total modulus
        */
        int n = s.length(), total = 0;
        
        // create left prefixes of size 2
        vector<int> countsLeft(10, 0), countsRight(10, 0);
        vector<vector<vector<int>>> leftPrefixCount(n, vector<vector<int>>(10, vector<int>(10)));
        for (int i=0; i<n; i++) {
            if (i > 0) 
                leftPrefixCount[i] = leftPrefixCount[i-1];
            int cur = s[i] - '0';
            for (int j=0; j<10; j++) {
                if (countsLeft[j] == 0) 
                    continue;
                leftPrefixCount[i][j][cur] += countsLeft[j];
            }
            countsLeft[cur]++;
        }

        // create right suffixes of size 2
        vector<vector<vector<int>>> rightSuffixCount(n, vector<vector<int>>(10, vector<int>(10)));
        for (int i=n-1; i>=0; i--) {
            if (i < n-1) 
                rightSuffixCount[i] = rightSuffixCount[i+1];
            int cur = s[i] - '0';
            for (int j=0; j<10; j++) {
                if (countsLeft[j] == 0) 
                    continue;
                rightSuffixCount[i][j][cur] += countsRight[j];
            }
            countsRight[cur]++;
        }
        
        // find all 5-length palindrome combinations using i as the center digit, leftPrefixCount as the left 2 digits,
        // and rightPrefixCount as the right 2 digits
        for (int i=2; i<n-2; i++) {
            vector<vector<int>> &left = leftPrefixCount[i-1], &right = rightSuffixCount[i+1];
            for (int i=0; i<10; i++) {
                for (int j=0; j<10; j++) {
                    total = (total + (1LL * left[i][j] * right[i][j])) % (int)(1e9 + 7);
                }
            }
        }
        
        return total;
    }
};