import java.util.*;

// 2021-06-22 
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> output = new ArrayList<List<Integer>>();
        
        for (int i = 0; i < (int) Math.pow(2.0, (double) nums.length); i++) {
            List<Integer> input = new ArrayList<Integer>();
            int count = 0;
            
            for (int x=i; x > 0; x /= 2) {
                if (x % 2 == 1)
                    input.add(nums[count]);
                count++;
            }
            output.add(input);
        }
        return output;
    }
}