import java.util.Arrays;

// 2021-04-29
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
            
        int count = 0;
        for (int i = 0; i < nums1.length; i++) {
            if (nums1[i] == 0 && count < n) {
                nums1[i] = nums2[count++];
            }
        }
        Arrays.sort(nums1);
    }
}

// 2021-11-11
class Solution2 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = m; i < nums1.length; i++) {
            nums1[i] = nums2[i-m];
        }
        Arrays.sort(nums1);
    }
}