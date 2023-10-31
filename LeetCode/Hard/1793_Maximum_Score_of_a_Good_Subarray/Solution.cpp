// 2022-10-22 (greedy)
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        /*
        notes:
        - score = minimum of subarray * length of subarray
        - i <= k and j >= k
        - need to optimize having the largest min value while keeping i and j on either end of k
        - probably need to mark down minimum value from k outwards? i.e. iterate from k to 0 and k to n-1, recording the
          smallest value encountered so far
            - having a small K is probably a limiting factor
        - we can end up with an O(n^2) solution from checking every recorded value above
            - potentially not optimal enough
        - maybe greedily expand outwards from K? since we need to include K anyways

        analysis:
        - time = O(n)
        - space = O(1)
        */
        int n = nums.size();
        int minVal = nums[k], maxScore = nums[k];
        int l = k, r = k;
        while(l > 0 || r < n-1) {
            if (l > 0 && r < n-1) {
                if (nums[l-1] > nums[r+1]) {
                    minVal = min(minVal, nums[--l]);
                } else {
                    minVal = min(minVal, nums[++r]);
                }
            } else if (l > 0) {
                minVal = min(minVal, nums[--l]);
            } else {
                minVal = min(minVal, nums[++r]);
            }
            maxScore = max(maxScore, minVal * (r-l+1));
        }

        return maxScore;
    }
};