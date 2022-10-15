// 2022-10-13 (ordered map)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        map<int, int> contains;
        int l = 0, r = 0, n = nums.size();

        while (r < n) {
            if (!contains.count(nums[r]))
                contains[nums[r]] = 0;
            contains[nums[r]]++;
            r++;
            
            if (r-l == k) {
                auto back = contains.rbegin();
                output.push_back(back->first);
                contains[nums[l]] -= 1;
                if (contains[nums[l]] == 0)
                    contains.erase(nums[l]);
                l++;
            }
        }

        return output;
    }
};