// 2022-05-27
/**
 * The solution is contingent on the array having only unique
 * elements from [0, n]. A regular array with elements from [0, n]
 * will have the sum of n*(n+1)/2 (summation). We can simply take the
 * expected value and subtract the sum we get from nums to see what
 * value was missing from nums.
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected = (n*(n+1))/2; // summation
        
        int total = 0;
        for (int num : nums)
            total += num;
        
        return expected - total;
    }
};