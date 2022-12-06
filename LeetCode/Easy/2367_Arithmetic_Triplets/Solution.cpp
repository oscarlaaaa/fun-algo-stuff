// 2022-09-22 (two-sum)
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        int n = nums.size();
        for (int i=0; i<n-2; i++) {
            unordered_set<int> need;
            for (int j=i+1; j<n; j++) {
                if (need.count(nums[j]))
                    count++;
                
                if (nums[j] - nums[i] == diff)
                    need.insert(nums[j]+diff);
            }
        }
        return count;
    }
};