from typing import *

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def findCombos(cur, lim, k, combos):
            if len(cur) == k:
                combos.append(cur[:])
                return
            
            if cur and cur[-1] == lim:
                return
            
            start = cur[-1]+1 if cur else 1
            for i in range(start, lim+1):
                cur.append(i)
                findCombos(cur, lim, k, combos)
                cur.pop()
            
        combos = []
        findCombos([], n, k, combos)
        return combos
            