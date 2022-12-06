// 2021-02-01
class Solution {
    int largest = 0;
    int sum;
    public int firstSolution(int[][] accounts) {
        for (int i = 0; i < accounts.length; i++) {
            sum = 0;
            for (int n = 0; n < accounts[i].length; n++) {
                // Adds each account value to sum
                sum += accounts[i][n];
            }
            if (sum >= largest) {
                largest = sum;
            }
        }
        return largest;
    }
}