import java.util.*;

// 2021-11-13 (O(n) space)
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> seen = new HashMap<Integer, Integer>();
        
        int left = 0;
        int right = numbers.length-1;
        
        while (left < right) {
            
            if (numbers[left] + numbers[right] == target) return new int[]{left+1, right+1};
            
            if (seen.containsKey(numbers[right])) return new int[]{seen.get(numbers[right]), right+1};
            if (seen.containsKey(numbers[left])) return new int[]{seen.get(numbers[left]), left+1};
                        
            if (numbers[left] + numbers[right] < target) {
                seen.put(target - numbers[left], left+1);
                left++;
            } else if (numbers[left] + numbers[right] > target) {
                seen.put(target - numbers[right], right+1);
                right--;
            }
        }
        
        return new int[]{-1, -1};
    }

    

}

// 2021-11-13 (O(1) space)
class Solution2 {
    public int[] twoSum(int[] numbers, int target) {
        
        int left = 0;
        int right = numbers.length-1;
        
        while (left < right) {
            
            if (numbers[left] + numbers[right] < target) {
                left++;
            } else if (numbers[left] + numbers[right] > target) {
                right--;
            } else {
                return new int[]{left+1, right+1};
            }
        }
        return new int[]{-1, -1};
    }
}