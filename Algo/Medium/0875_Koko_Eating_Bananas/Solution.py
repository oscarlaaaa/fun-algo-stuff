from math import *
from typing import *

## 2022-08-29 (binary search)
# 
# Given that we need to find a value within a defined range (koko can eat at a speed of
# 1 to X bananas/hr), we can utilize binary search to cut down the number of values we
# need to search through.
# 
class Solution:
    def timeToEatAll(self, piles, speed) -> int:
        return sum([ceil(pile/speed) for pile in piles])
        
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        lo, hi = 1, max(piles)
        cur_min = hi
        while lo <= hi:
            mid = lo + (hi-lo)//2
            duration = self.timeToEatAll(piles, mid)
            
            if duration <= h:
                cur_min = mid
                hi = mid-1
            else:
                lo = mid+1
        
        return cur_min