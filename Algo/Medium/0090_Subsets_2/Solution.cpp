// 2022-05-18
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};
        sort(nums.begin(), nums.end());
        
        int idx = 0;
        while (idx < nums.size()) {
            int cur = nums[idx];
            vector<vector<int>> oldSubsets = subsets;           
            while (idx < nums.size() && nums[idx] == cur) {
                vector<vector<int>> newSubsets;
                for (vector<int> set : oldSubsets) {
                    vector<int> newSubset = set;
                    newSubset.push_back(cur);
                    newSubsets.push_back(newSubset);
                }
                subsets.insert(subsets.end(), newSubsets.begin(), newSubsets.end());
                oldSubsets = move(newSubsets);
                idx++;
            }
        }
        return subsets;
    }
};
