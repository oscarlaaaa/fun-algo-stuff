// 2021-08-30
class Solution {
    public int findMin(int[] nums) {
        if (nums.length == 1) return nums[0];
        int left = 0;
        int right = nums.length - 1;
        int lowest = Math.min(nums[left], nums[right]);
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            lowest = Math.min(nums[mid], lowest);
            if (nums[left] > nums[right]) {
                if (nums[mid] > nums[left]) {
                    left = mid;
                } else {
                    right = mid;
                }
            } else {
                break;
            }
        }
        
        return lowest;
    }
}