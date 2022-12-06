
// 2021-11-11
class Solution {
    public int maxProfit(int[] prices) {
        // base case; no need to check if only 1 day
        if (prices.length == 1) return 0;
        
        // initialize variables
        int currBought = -1;
        int nextDay = 1;
        int sum = 0;
        
        for (int curDay = 0; curDay < prices.length; curDay++) {
            
            // check if we are on the last day
            if (nextDay == prices.length) {
                
                // if we bought a stock and its price is lower than today's price, sell
                if (currBought != -1 && currBought < prices[curDay]) {
                        sum += prices[curDay] - currBought;
                } 
            
                // if we have no stock bought and today's price is less than tomorrows, buy
            } else if (currBought == -1) {
                if (prices[curDay] < prices[nextDay]) {
                    currBought = prices[curDay];
                }
            } else {
                
                // if we have a stock and today's price is more than tomorrows, sell
                if (prices[curDay] > prices[nextDay]) {
                    sum += prices[curDay] - currBought;
                    currBought = -1;
                }
            }
            ++nextDay;
        }
        return sum;
    }
}
