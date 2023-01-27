// 2023-01-26 (cumsum)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
            input: a list of nums, and a k sum
            output: the number of subarrays that sum up to K

            notes:
            - the whole idea with this is that we can prefix sum then do kinda a two-sum approach
            - we can store cumulative-sums into our map, and basically go off of the logic that:
                - if a cumsum - a previous cumsum = k, then the subarray will have the sum of k
                - we can then conclude that we can find previous cumsums by looking for current cumsum - k
                  in our map
            - as such, we can count occurrences of cumsums within our map and basically find how many subarrays
              each cumsum can pair up with, then add it to our map for future cumsums

            approach:
            - process nums into a cumulative-sum list from left to right
            - initialize a map that tracks the number of subarray sums of each value
            - iterate through our cumulative sum list
                - if the value-k is found in our map, then increment count by the stored value
                - increment current value in our map
        */
        int n = nums.size();
        for (int i=0; i<n-1; i++) {
            nums[i+1] += nums[i];
        }

        int count = 0;
        unordered_map<int, int> need;
        need[0]++;
        for (int i=0; i<n; i++) {
            if (need.count(nums[i]-k))
                count += need[nums[i]-k];
            need[nums[i]]++;
        }
        
        return count;
    }
};