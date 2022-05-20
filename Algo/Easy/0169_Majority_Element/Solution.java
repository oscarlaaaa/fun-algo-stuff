import java.util.*;

// 2021-06-09 (O(n) space)
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<Integer, Integer>();
        counts.put(nums[0], 1);
        int currentMax = nums[0];
        int maxCount = 1;
        
        for (int i = 1; i < nums.length; i++) {
            
            int current = counts.getOrDefault(nums[i], 0);
            counts.put(nums[i], ++current);
            
            if (counts.get(nums[i]) > maxCount) {
                currentMax = nums[i];
                maxCount = counts.get(nums[i]);
            }
                
            if (maxCount > nums.length / 2) break;
        }
        
        return currentMax;
    }
}