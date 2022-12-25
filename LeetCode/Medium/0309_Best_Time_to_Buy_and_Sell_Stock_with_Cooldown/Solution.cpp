// 2022-12-22 (O(n^2) tabulation dp)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            input: list of int prices where price[i] = price on day i
            output: maximum profit we can achieve

            notes:
            - as many transactions we want, with restrictions
              - cannot buy stock the day after we sell
              - must sell before buying more
            
            approach:
            - maybe 1d DP vibes? 
            - could do an O(n^2) where we use 2 pointers
            - left pointer = buy, right = sell
            - int vector where vector[i] represents max profit we can achieve by that day while
              also being able to still buy stock
            - for each possible future sell where we can profit, see if our current profit + profit from
              the transaction will be greater than the profit at the selling date+2 (we do +2 to account for
              the 1 day cooldown where we are unable to purchase stonk)
            - carry our current profit forward if it's greater than the next day's (we don't want to operate on
              a lower possible profit when we can get higher from skipping a day or two)
            - return the last position of our vector
        */
        int n = prices.size();
        vector<int> maxProfits(n+2);
        for (int i=0; i<=n; i++) {
            for (int j=i+1; j<n; j++) {
                if (prices[i] >= prices[j]) 
                    continue;
                int profitIfSell = maxProfits[i] + prices[j] - prices[i];
                maxProfits[j+2] = max(maxProfits[j+2], profitIfSell);
            }
            
            // if our current profit is greater than tomorrows, base tomorrow off of today's profit
            maxProfits[i+1] = max(maxProfits[i+1], maxProfits[i]);
        }
        return maxProfits[n+1];
    }
};