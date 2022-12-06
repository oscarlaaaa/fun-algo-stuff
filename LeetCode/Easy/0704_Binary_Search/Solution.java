// 2021-08-01
class Solution {
    public int search(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        if (nums[low] == target) return low;
        if (nums[high] == target) return high;
        
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            } else {
                if (nums[mid] < target) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
        }
        
        return -1;
    }
}