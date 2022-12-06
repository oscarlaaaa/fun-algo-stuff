// 2021-01-29
class Solution {
    public int[] runningSum(int[] nums) {
        int total = 0;
        for (int i=0; i<nums.length; i++) {
            total += nums[i];
            nums[i] = total;
        }
        return nums;
    }
}