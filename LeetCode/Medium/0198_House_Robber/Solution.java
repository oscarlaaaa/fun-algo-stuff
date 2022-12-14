// 2021-08-27 (tabulation dp)
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) return nums[0];
        int[] tab = new int[nums.length + 1];
        tab[0] = nums[0];
        tab[1] = nums[1];
        for (int i = 0; i < nums.length; i++) {
            if (tab[i] != 0) {
                if (i + 2 < nums.length) {
                    int skip1 = tab[i] + nums[i + 2];
                    tab[i + 2] = Math.max(tab[i + 2], skip1);
                }
                if (i + 3 < nums.length) {
                    int skip1 = tab[i] + nums[i + 3];
                    tab[i + 3] = Math.max(tab[i + 3], skip1);
                }
                tab[nums.length] = Math.max(tab[i], tab[nums.length]);
            }
        }
        return tab[nums.length];
    }
}