// 2021-11-08
class Solution {
    public int searchInsert(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int mid = start + (end - start)/2;
        
        if (nums[start] >= target) return start;
        if (nums[mid] == target) return mid;
        if (nums[end] == target) return end;
        if (nums[end] < target) return end + 1;
        
        while (start < end - 1 && nums[mid] != target) {
            if (nums[mid] > target) {
                end = mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                return mid;
            }
        
            mid = start + (end - start)/2;
        }
        
        return nums[mid] < target ? mid + 1 : mid;
    }
}
