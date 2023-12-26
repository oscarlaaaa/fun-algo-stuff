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

// 2023-12-25 (tabulation dp)
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        /*
        notes:
        - need to find number of permutations of dice to get target
        - seems like this is just DP?
        - n and k limited to 30, so we can just do sums between
          0 and target, as well as n slots or something?
        - can just do 2 vectors? maps? and swap data to minimize space

        analysis:
        - time = O(nkt)
        - space = O(t)
        */
        const int MOD = 1e9 + 7;
        vector<int> sumCounts(target+1, 0);
        sumCounts[0] = 1;

        for (int i=0; i<n; i++) {
            vector<int> nextSumCounts(target+1, 0);
            for (int curSum=0; curSum<=target; curSum++) {
                if (sumCounts[curSum] == 0) {
                    continue;
                }
                for (int roll=1; roll<=k; roll++) {
                    if (curSum+roll > target) {
                        break;
                    }
                    nextSumCounts[curSum+roll] = (1LL * nextSumCounts[curSum+roll] + sumCounts[curSum])%MOD;
                }
            }
            sumCounts.swap(nextSumCounts);
        }

        return sumCounts[target];
    }
};