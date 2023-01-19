// 2023-01-19 (sliding window)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        /*
            input: circular int list of length n
            output: max sum of a non-empty subarray

            notes:
            - probably use modulus to loop around the list
            - sliding window? just need to make sure the ends don't overlap
            - because we just want the max possible sum, we expand until our
              total reaches 0/below zero, to which we start anew 1 space ahead
            - what if we try to find the subarray with the minimum sum?
                - can think about it as tracking the area to exclude from our subarray
            
            approach:
            - iterate over list 2 times, once to find area to include and once to find area to exclude
                - the idea is that we can include an area in the middle, or exclude an area in the middle
                  to represent the included area being wrapped from end to end
            - left and right pointer to track sliding window, plus window sum
            - iterate right pointer forward, add to window sum, and track current max sum
                - shrink if window sum dips below or equal to 0 (not worth including in our subarray)
            - repeat to find the minimum sum
                - don't keep if l-r == n since we don't want to exclude the entire list; want a non-empty subarray
                - can find the included portion by subtracting the minimum from the total list sum
            - return the max of our (max sum) vs (list sum - minimum sum)
        */
        int n = nums.size(), numsTotal = accumulate(nums.begin(), nums.end(), 0);;
        int curMax = nums[0];

        // find greatest area to include
        int windowSum = 0;
        for (int r=0, l=0; r<n; r++) {
            while (l < r && windowSum <= 0) {
                windowSum -= nums[l++];
                if (l != r)
                    curMax = max(curMax, windowSum);
            }
            windowSum += nums[r];
            curMax = max(curMax, windowSum);
        }

        // find lowest area to exclude
        windowSum = 0;
        for (int r=0, l=0; r<n; r++) {
            while (l < r && windowSum >= 0) {
                windowSum -= nums[l++];
                if (l != r)
                    curMax = max(curMax, numsTotal-windowSum);
            } 
            windowSum += nums[r];
            if (r-l < n-1) // we want a non-empty subarray so don't exclude everything
                curMax = max(curMax, numsTotal-windowSum);
        }
        return curMax;
    }
};

// 2023-01-19 (kadanes)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        /*
            input: circular int list of length n
            output: max sum of a non-empty subarray

            approach:
            - iterate over list 2 times, once to find area to include and once to find area to exclude
                - the idea is that we can include an area in the middle, or exclude an area in the middle
                  to represent the included area being wrapped from end to end
            - Kadane's algo to find the greatest/lowest areas
            - return the max of our (max sum) vs (list sum - minimum sum) IF curMax is not negative
                - if it is negative, that'd mean our curMin would try to exclude the entire list thus we
                  shouldn't consider  total - minimumSubarray as a valid result

            analysis:
            - time = O(n) where n = length of list
            - space = O(1)
        */
        int n = nums.size(), numsTotal = accumulate(nums.begin(), nums.end(), 0);;

        // find greatest area to include
        int windowSum = 0;
        int curMax = nums[0];
        for (int r=0; r<n; r++) {
            windowSum = max(nums[r], windowSum+nums[r]);
            curMax = max(curMax, windowSum);
        }

        // find lowest area to exclude
        windowSum = 0;
        int curMin = nums[0];
        for (int r=0; r<n; r++) {
            windowSum = min(nums[r], windowSum+nums[r]);
            curMin = min(curMin, windowSum); 
        }
        
        return curMax > 0 ? max(curMax, numsTotal-curMin) : curMax;
    }
};