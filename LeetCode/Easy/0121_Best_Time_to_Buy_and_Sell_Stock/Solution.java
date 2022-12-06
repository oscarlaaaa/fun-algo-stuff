
// 2021-03-25
class Solution {
    public int maxProfit(int[] prices) {
        int minProfit = 0;
        int low = prices[0];
        for (int i=1; i<prices.length; i++) {
            if (prices[i] < low) {
                low = prices[i];
            } else if (prices[i] - low > minProfit) {
                minProfit = prices[i] - low;
            }
        }
        return minProfit;
    }
}