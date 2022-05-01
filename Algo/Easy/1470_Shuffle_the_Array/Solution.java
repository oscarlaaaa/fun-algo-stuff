// 2021-02-01
class Solution {
    public int[] shuffle(int[] nums, int n) {
        final int doubleN = 2 * n;
        int[] answer = new int[doubleN];
        int countN = 0;
        
        for (int i=0; i<doubleN; i++) { 
           if ((i % 2) == 0) {
                answer[i] = nums[i - countN];
            } else {
                answer[i] = nums[n + countN];
                countN++;
            } 
        }
        
        return answer;
    }
}

