import java.util.Arrays;

// 2021-04-29
class Solution {
    public int removeElement(int[] nums, int val) {
        Arrays.sort(nums);
        int first = 0;
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == val && count == 0) {
                first = i;
                count++;
            } else if (nums[i] == val) {
                count++;
            }
        }
        int position = nums.length - 1;
        for (int n = first; n < first + count; n++) {
            int hold = nums[position];
            nums[position--] = nums[n];
            nums[n] = hold;
        }
        
        return nums.length - count;
    }
}