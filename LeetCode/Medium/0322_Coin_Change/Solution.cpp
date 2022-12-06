#define ll long long

// 2022-05-20 (tabulation)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        vector<int> memo(amount+1);
        for (int coin : coins) {
            if (coin <= amount)
                memo[coin] = 1;
        }
        
        for (int i = 1; i < memo.size(); i++) {
            if (memo[i] == 0) 
                continue;
                
            for (ll val : coins) {
                if (i + val > amount) 
                    continue;
                
                if (memo[i+val] == 0) 
                    memo[i+val] = memo[i] + 1;
                else
                    memo[i+val] = min(memo[i+val], memo[i] + 1);
            }
        }

        return memo[amount] > 0 ? memo[amount] : -1;
    }
};

// 2022-05-20 (memoization)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        vector<int> memo(amount+1);
        int letsgo = tryChange(coins, amount, memo);
        return letsgo;
    }
    
    int tryChange(vector<int>& coins, int remain, vector<int>& memo) {
        if (remain == 0) return 0; // target reached
        if (remain < 0) return -1; // nooo too far
        
        if (memo[remain] != 0) // seen it B)
            return memo[remain];
        
        int fewest = -1;
        for (int coin : coins) {
            int tryThisCoin = tryChange(coins, remain-coin, memo);

            if (tryThisCoin != -1)
                fewest = fewest == -1 ? 1+tryThisCoin : min(fewest, 1+tryThisCoin);
        }
        
        memo[remain] = fewest;
        return fewest;
    }
};