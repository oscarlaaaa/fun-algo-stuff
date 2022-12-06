from typing import *

## 2022-05-10
class Solution:
    UPPER_BOUND = 10
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        combos = []
        self.findCombos([], k, n, combos)
        return combos
    
    def findCombos(self, current, k, n, combos):
        if k == 0:
            if n == 0:
                combos.append(current[:])
            return
        
        lower_bound = 1 if len(current) == 0 else current[-1]+1
        for i in range(lower_bound, Solution.UPPER_BOUND):
            if n-i < 0:
                break
                
            current.append(i)
            self.findCombos(current, k-1, n-i, combos)
            current.pop()
