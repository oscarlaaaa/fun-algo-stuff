from typing import *

## 2022-03-05
class Solution:
    def countOrders(self, n: int) -> int:
        slotCounts = [val for val in range(0, 2*n + 1)]
        for i in range(0, 2*n):
            slotCounts[i+1] += slotCounts[i]
        
        counts = [0]*(n+1)
        counts[1] = 1
        for i in range(2, n+1):
            previous = counts[i-1]
            sizeOfPrevious = (i-1)*2  ## when n=i-1, you have i-1 deliveries and i-1 pickups
            combos = slotCounts[sizeOfPrevious+1]  ## +1 as if you have 2*n orders, you have 2*n+1 slots
            counts[i] = combos * counts[i-1]
        
        return counts[n] % (10**9 + 7)
        