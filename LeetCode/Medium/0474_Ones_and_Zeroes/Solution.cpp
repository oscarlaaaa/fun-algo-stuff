// 2022-05-22 (tabulation approach)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // greatest substring counts with total x 0's and y 1's
        int memo[m+1][n+1];
        memset(memo, -1, sizeof memo);
        memo[0][0] = 0;
        
        // keeps track of which ones we've updated using this word already
        int skip[m+1][n+1];
        memset(skip, -1, sizeof skip);

        for (int i = 0; i < strs.size(); i++) {
            int counts[] = {0, 0};
            for (char c : strs[i]) {
                int val = c - '0';
                counts[val]++;
            }
            
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    memo[m][n] = max(memo[m][n], memo[j][k]); // always check to update our largest
                    
                    // skip if not reached or we have updated using this word already
                    if (memo[j][k] == -1 || skip[j][k] == i) continue; 
                    
                    if (j+counts[0] <= m && k+counts[1] <= n) {
                        if (memo[j+counts[0]][k+counts[1]] < 1+memo[j][k]) {
                            memo[j+counts[0]][k+counts[1]] = 1+memo[j][k];
                            skip[j+counts[0]][k+counts[1]] = i;
                        }
                    } 
                }
            }
        }
        
        return memo[m][n];
    }
};