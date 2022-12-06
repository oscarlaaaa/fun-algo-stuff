// 2022-05-22 (Brute Force with memoization - TLE)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int totalCoins = 0;
        
        // remove all zeroes
        vector<int> cleaned;
        for (int i = 0; i < nums.size(); i++) 
            if (nums[i] > 0) cleaned.push_back(nums[i]);
            
        unordered_map<vector<bool>, int> memo;
        vector<bool> popped(cleaned.size(), false);
        int val = totalCoins + maxOfAllPops(cleaned, cleaned.size(), popped, memo);
        return val;
    }
    
    int maxOfAllPops(vector<int>& balloons, int remaining, vector<bool> &popped, unordered_map<vector<bool>, int>& memo) {
        if (remaining == 0) return 0;
        if (memo.count(popped)) return memo[popped];
        
        vector<int> unpopped;
        for (int i = 0; i < balloons.size(); i++) {
            if (!popped[i]) {
                unpopped.push_back(i);
            }
        }
        
        int greatest = 0;
        for (int i = 0; i < unpopped.size(); i++) {
            int left = i-1 >= 0 ? balloons[unpopped[i-1]] : 1;
            int right = i+1 < unpopped.size() ? balloons[unpopped[i+1]] : 1;
            
            popped[unpopped[i]] = true;
            int popCurrent = (left * right * balloons[unpopped[i]]) + maxOfAllPops(balloons, remaining-1, popped, memo);
            popped[unpopped[i]] = false;
            
            greatest = max(greatest, popCurrent);
        }
        
        memo[popped] = greatest;
        return greatest;
    }
};