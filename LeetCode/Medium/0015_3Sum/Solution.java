import java.util.*;

// 2021-08-17
class Solution {
    private static List<List<Integer>> output;
    
    public List<List<Integer>> threeSum(int[] nums) {
        output = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        
        for (int first = 0; first < nums.length - 2; first++) {
                
            int num1 = nums[first];
            
            // if the first number is positive, impossible to have sum of 0 as list is sorted
            if (num1 > 0) break;
            
            // target to reach; 2nd + 3rd number must offset 1st number
            int target = -(nums[first]);
            
            int last = nums.length - 1;
            int middle = first + 1;
            
            while (middle < last) {
                if (nums[middle] + nums[last] > target) {
                    --last;
                } else if (nums[middle] + nums[last] < target) {
                    ++middle;
                } else {
                    int num2 = nums[middle], num3 = nums[last];
                    addOutput(num1, num2, num3);
                    
                    // makes sure no duplicates are checked
                    while (middle < last && nums[middle] == num2) ++middle;
                    while (middle < last && nums[last] == num3) --last;
                }
            }
            // check 1 ahead of the first because the incremental operator of the for loop will occur after
            while (first < nums.length - 2 && nums[first + 1] == num1) first++;
        }
        return output;
    }
    
    // adds a group of numbers to the output
    private static void addOutput(int num1, int num2, int num3) {
        List<Integer> newEntry = new ArrayList<Integer>();
        newEntry.add(num1);
        newEntry.add(num2);
        newEntry.add(num3);
        output.add(newEntry);
    }
}