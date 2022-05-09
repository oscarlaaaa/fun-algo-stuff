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