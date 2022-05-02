// 2021-01-30
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] answer = new int[2];
        int length = nums.length;
        for (int i=0; i<length; i++) {
            for (int n=i+1; n<length; n++) {
                if ((nums[i] + nums[n]) == target) {
                    answer[0] = i;
                    answer[1] = n;
                }
            }
        }
        return answer;
    }
}

// 2021-11-11
class Solution2 {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> need = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (need.containsKey(nums[i])) {
                return new int[]{need.get(nums[i]), i};
            }
            need.put(target - nums[i], i);
        }
        return null;
    }
}