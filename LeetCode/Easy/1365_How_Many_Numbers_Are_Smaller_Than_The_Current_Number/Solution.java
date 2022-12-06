//2021-02-10
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] answer = new int[nums.length];
        for(int i=0; i<nums.length; i++){
            int count = 0;
            for (int n=0; n<nums.length; n++){
                if (nums[i] > nums[n]){
                    ++count;
                }
            }
            answer[i] = count;
        }
        return answer;
    }
}