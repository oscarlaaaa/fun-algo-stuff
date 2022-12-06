// 2022-06-12
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int sum = 0, maximum = 0;
        
        int left = 0, right = 0;
        while (right < nums.size()) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                sum -= nums[left++];
            }
            seen.insert(nums[right]);
            sum += nums[right++];
            maximum = max(maximum, sum);
        }
        
        return maximum;
    }
};