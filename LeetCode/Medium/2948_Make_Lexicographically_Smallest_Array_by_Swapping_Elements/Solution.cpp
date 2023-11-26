// 2023-11-25 (grouping)
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        /*
        notes:
        - sort all values with a map
        - loop through and assign numbers to groups
        - group and sort all numbers within the same groups
        - create smallest array based on numbers
        
        */
        int n = nums.size();
        map<int, int> counts;
        unordered_map<int, vector<int>> positions;
        for (int i=0; i<n; i++) {
            counts[nums[i]]++;
            positions[nums[i]].push_back(i);
        }    
        
        unordered_map<int, int> groupNums;
        vector<vector<int>> groups;
        for (auto [k, v] : counts) {
            if (groups.empty() || (k - groups.back().back()) > limit) {
                groups.push_back({});
            }
            for (int i=0; i<v; i++) {
                groups.back().push_back(k);
            }
            groupNums[k] = groups.size()-1;
        }
        
        for (vector<int>& group : groups) {
            sort(group.rbegin(), group.rend());
        }
        
        vector<int> output;
        for (int num : nums) {
            output.push_back(groups[groupNums[num]].back());
            groups[groupNums[num]].pop_back();
        }
        
        return output;
    }
};