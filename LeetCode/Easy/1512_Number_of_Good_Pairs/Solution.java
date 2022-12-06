// 2021-02-02
class Solution {
    // Our output
    int answer = 0;
    public int numIdenticalPairs(int[] nums) {
        for (int i=0; i<(nums.length - 1); i++){
            for (int n=0; n<nums.length; n++){
                if ((nums[i] == nums[n]) && (i < n)){
                    answer++;
                }
            }
        }
        return answer;
    }
}   