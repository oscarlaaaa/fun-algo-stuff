// 2021-04-29
class Solution {
    public int removeDuplicates(int[] nums) {
        int length = nums.length; 
        int pos1 = 0;
        int pos2 = 0;
        
        if (length == 0) {
            return 0;
        } else {
            
            while (pos1 < length && pos2 < nums.length) {
                if (nums[pos1] >= nums[pos2]) {
                    pos2++;
                } else {
                    nums[++pos1] = nums[pos2];
                }
            }
            
        }
        return pos1 + 1;
    }
}
