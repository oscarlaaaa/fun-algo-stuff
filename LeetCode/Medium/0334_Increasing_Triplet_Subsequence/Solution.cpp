// 2022-10-13 (largest increasing sequence)
//
// Time = O(n*log(3)) = O(n)
// Space = O(3) = O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> increasing;
        for (int num : nums) {
            // find and replace the value this is smaller by
            auto itr = lower_bound(increasing.begin(), increasing.end(), num);
            if (itr == increasing.end()) {
                increasing.push_back(num);
            } else {
                *itr = num;
            }
            
            if (increasing.size() >= 3)
                return true;
        }
        return false;
    }
};