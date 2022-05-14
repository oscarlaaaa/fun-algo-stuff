// 2022-05-14 (2-pass)
class Solution {
    public void sortColors(int[] nums) {
        int left = 0;
        for (int i = left+1; i < nums.length; i++) {
            while (left < i && nums[left] == 0) left++;
            if (nums[i] == 0) {
                int temp = nums[left];
                nums[left] = nums[i];
                nums[i] = temp;
            }
        }
        while (left < nums.length && nums[left] == 0) left++;
        for (int i = left+1; i < nums.length; i++) {
            while (left < i && nums[left] == 1) left++;
            if (nums[i] == 1) {
                int temp = nums[left];
                nums[left] = nums[i];
                nums[i] = temp;
            }
        }
    }
}

// 2022-05-14 (Counting Sort)
class Solution2 {
    public void sortColors(int[] nums) {
        int[] counts = new int[3];
        for (int num : nums) {
            counts[num]++;
        }
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            while (counts[i] > 0) {
                nums[idx] = i;
                counts[i]--;
                idx++;
            }
        }
    }
}