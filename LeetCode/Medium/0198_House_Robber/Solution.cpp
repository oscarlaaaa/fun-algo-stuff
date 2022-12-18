// 2022-12-13 (tabulation dp)
class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            input: list of integers with list[i] being $ in the house
            output: maximum amount of money robbable without alerting the police

            notes:
            - cannot rob adjacent houses
            - not circular, so can rob first and last houses

            approach:
            - initialize tabulation dp of max money earnable by that position
            - apply max of current money + money at house[i+2] as well as house[i+3]
            - return the maximum of the list
        */
        int n = nums.size();
        vector<int> maximums = nums;
        for (int i=0; i<n; i++) {
            if (i+2 < n) 
                maximums[i+2] = max(maximums[i+2], maximums[i]+nums[i+2]);
            if (i+3 < n) 
                maximums[i+3] = max(maximums[i+3], maximums[i]+nums[i+3]);
        }

        return *max_element(maximums.begin(), maximums.end());
    }
};