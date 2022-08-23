from typing import *

## 2022-01-31
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        current_stock = prices[0]
        
        for i in range(1, len(prices)):
            current_stock = min(current_stock, prices[i])
            max_profit = max(max_profit, prices[i] - current_stock)
        
        return max_profit

## 2022-08-22
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 1:
            return 0
        
        profit = 0
        cheapest = prices[0]
        for i in range(1, len(prices)):
            profit = max(profit, prices[i] - cheapest)
            if prices[i] < cheapest:
                cheapest = prices[i]
        
        return profit
        