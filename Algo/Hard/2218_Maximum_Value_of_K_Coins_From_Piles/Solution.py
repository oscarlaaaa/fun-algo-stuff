from typing import *

# 2022-04-21 (very bad time complexity, but solves)
class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        cost_vals = [[] for _ in range(len(piles))]
        for x, pile in enumerate(piles):
            total = 0
            for i, v in enumerate(pile):
                total += v
                cost_vals[x].append((i+1, total)) #cv = (layers deep, how much you'd get by digging here)
        
        memo = [[-1 for _ in range(k+1)] for i in range(len(piles))]
        return self.findMax(cost_vals, 0, k, memo)
    
    def findMax(self, cvs, pile, remaining, memo):
        if pile >= len(cvs):
            return 0
        
        if memo[pile][remaining] != -1:
            return memo[pile][remaining]
        
        maximum = 0
        skip = self.findMax(cvs, pile+1, remaining, memo) # skip the current pile
        for cv in cvs[pile]:
            if cv[0] > remaining:
                continue
            check = cv[1] + self.findMax(cvs, pile+1, remaining-cv[0], memo)
            maximum = max(maximum, check)
            
        skip = self.findMax(cvs, pile+1, remaining, memo)
            
        memo[pile][remaining] = max(maximum, skip)
        return memo[pile][remaining]
