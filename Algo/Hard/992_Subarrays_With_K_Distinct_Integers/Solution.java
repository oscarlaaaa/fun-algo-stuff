import java.util.*;

// 2022-08-20
class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {

        // keeps track of how many distinct we've seen (size) and counts of each
        Map<Integer, Integer> seen = new HashMap<Integer, Integer>();
        
        int output = 0;
        int start = 0;
        
        // output incremental count - how many distinct pairs as a result of an addition
        int count = 1;

        for (int i = 0; i < nums.length; i++) {
            seen.put(nums[i], seen.getOrDefault(nums[i], 0) + 1);
            
            // if we've went over k, then reset count back to 1
            if (seen.size() > k) count = 1;

            // remove values from our hashmap from our start pointer and increment it until size == k
            while (seen.size() > k && start <= i) {
                if (seen.get(nums[start]) == 1) {
                    seen.remove(nums[start]);
                } else {
                    seen.put(nums[start], seen.get(nums[start]) - 1);
                }
                ++start;
            }
                
            // while we are == k, remove duplicates and increment our counter for each one
            while (seen.size() == k && start <= i) {
                // if we hit a non-duplicate, stop
                if (seen.get(nums[start]) == 1) {
                    break;
                } else {
                    seen.put(nums[start], seen.get(nums[start]) - 1);
                    ++count;
                }
                ++start;
            }
            
            // increment output based on count only if seen.size == k (prevents increments from seen < k)
            if (seen.size() == k) output += count;
        }
        return output;
    }
}