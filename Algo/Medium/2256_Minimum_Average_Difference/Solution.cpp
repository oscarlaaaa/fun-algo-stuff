// 2022-12-03 (cumulative sum)
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        /*
            input: vector of ints
            output: index with the minimum average difference

            notes:
            - average difference at index i = abs(nums[0:i+1] - nums[i+1:n]) 
            - average of 0 elements = 0

            approach:
            - instantiate 2 vectors of size n
            - cumulative sum from left to right, store the average
            - repeat for right to left in the other vector
            - iterate from -1 to n; take left average for i and right average for i+1
            - record minimum diff and return
        */
        int n = nums.size();
        vector<int> leftAvg(n), rightAvg(n);
        
        // generate left and right cumulative sums
        long long sumLeft = 0, sumRight = 0;
        for (int i=0; i<n; i++) {
            sumLeft += nums[i];
            leftAvg[i] = sumLeft/(i+1);

            sumRight += nums[n-i-1];
            rightAvg[n-i-1] = sumRight/(i+1);
        }

        // find the min abs diff
        int minIdx = -1, minDiff = INT_MAX;
        for (int i=0; i<n; i++) {
            int left = leftAvg[i], right = (i<n-1 ? rightAvg[i+1] : 0);
            int diff = abs(left - right);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i;
            }
        }
        
        return minIdx;
    }
};