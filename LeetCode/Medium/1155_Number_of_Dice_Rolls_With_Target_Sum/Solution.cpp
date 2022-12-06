// 2022-10-02 (iterative DP)
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // memo represents a position where memo[n][m] is the number of ways we can reach
        // m sum using n dice
        vector<vector<int>> memo = vector<vector<int>>(n+1, vector<int>(target+1, 0));
        memo[0][0] = 1; 

        for (int diceUsed=0; diceUsed<n; diceUsed++) {
            for (int val=0; val<target; val++) {
                // if the current position == 0, means we couldn't reach it anyways
                if (memo[diceUsed][val] == 0) 
                    continue;

                // add the number of ways we can reach our current position to all
                // possible rolls of our next dice
                for (int i=1; i<=k; i++) {
                    if (val+i > target || diceUsed+1 > n) 
                        break;

                    memo[diceUsed+1][val+i] = (memo[diceUsed+1][val+i] 
                        + memo[diceUsed][val]) % 1000000007;
                }
            }
        }
        
        return memo[n][target];
    }
};