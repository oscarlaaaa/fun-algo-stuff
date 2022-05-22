from typing import *

## 2022-02-17
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profits = [[0, 0] for i in prices]
        
        ## calculate highest possible transaction up to i from the left
        left_lowest = prices[0]
        left_profit = 0
        for i in range(len(prices)):
            left_profit = max(left_profit, prices[i] - left_lowest)
            if prices[i] < left_lowest:
                left_lowest = prices[i]
            profits[i][0] = left_profit
        
        
        ## calculate highest possible transaction up to i from the right
        right_highest = prices[-1]
        right_profit = 0
        for i in range(len(prices)-1, -1, -1):
            right_profit = max(right_profit, right_highest - prices[i])
            if prices[i] > right_highest:
                right_highest = prices[i]
            profits[i][1] = right_profit

        ## find the breakpoint where left highest + right highest = max
        return max([sum(profit) for profit in profits])
            