// 2022-05-26
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i])) {
                return {seen[nums[i]], i};
            }
            seen[target - nums[i]] = i;
        }
        return {-1, -1};
    }
};