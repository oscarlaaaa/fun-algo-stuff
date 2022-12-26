// 2021-10-09 (brute force approach)
class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length == 1) return true;
        boolean[] failed = new boolean[nums.length];
        Arrays.fill(failed, false);
        
        return jumpForwards(nums, 0, failed);
    }
    
    private static boolean jumpForwards(int[] nums, int pos, boolean[] failed) {
        if (pos >= nums.length - 1) return true;
        if (failed[pos]) return false;
        
        for (int i = nums[pos]; i >= 1; i--) {
            if (jumpForwards(nums, pos + i, failed)) {
                return true;
            }
        }
        
        failed[pos] = true;
        return false;
    }
}