import java.util.*;

// 2021-05-11
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] output = new int[nums.length];
        int prod = 1;
        int zeroes = 0;
        int zeroindex = 0;
        
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                zeroes++;
                zeroindex = i;
            } else {
                prod *= nums[i];
            }
        }
        
        Arrays.fill(output, 0);
        
        if (zeroes > 1) return output;
        
        if (zeroes == 1) {
            output[zeroindex] = prod;
            return output;
        }
        
        for (int n = 0; n < output.length; n++) {
            output[n] = prod / nums[n];
        }
        return output;
    }
}

// 2021-06-29
class Solution2 {
    public int[] productExceptSelf(int[] nums) {
        int[] output = new int[nums.length];
        int total = 1;
        
        for (int right = 0; right < nums.length; right++) {
            output[right] = total;
            total *= nums[right];
        }
        
        total = 1;
        for (int left = nums.length - 1; left >= 0; left--) {
            output[left] *= total;
            total *= nums[left];
        }
        
        return output;
    }
}