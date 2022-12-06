// 2021-05-10
class Solution {
    public int maxSubArray(int[] nums) {
        int max = nums[0];
        if (nums.length == 1) return max;
        
        int sum = max;
        for (int i = 1; i < nums.length; i++) {
            sum += nums[i];
            if (nums[i] > sum)
                sum = nums[i];
            if (sum > max)
                max = sum;
        }
        return max;
    }
}

// 2021-11-08
class Solution2 {
    public int maxSubArray(int[] nums) {
        
        int sum = nums[0];
        int max = sum;
        
        for (int i = 1; i < nums.length; i++) {
            sum += nums[i];
            if (nums[i] > sum)
                sum = nums[i];
            if (sum > max)
                max = sum;
        }
        
        return max;
    }
}