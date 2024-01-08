// 2021-07-24
class Solution {
    
    private int[] nums;
    private int[] longests;

    
    private int solve(int pos) {
        if (longests[pos] != 0) return longests[pos];
        
        int max = 1;
        for (int x = pos; x < nums.length; x++) {
            if (nums[x] > nums[pos]) {
                int xd = 1 + solve(x);
                max = Math.max(max, xd);
            }
        }
        longests[pos] = max;
        return max;
    }
    
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 1) return 1;
        this.nums = nums;
        longests = new int[nums.length];
        int output = 0;
        for (int i = 0; i < nums.length; i++) {
            int xd = solve(i);
            output = Math.max(output, xd);
        }
        return output;
    }
}