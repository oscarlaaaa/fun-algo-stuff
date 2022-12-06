from typing import *

## 2022-01-16
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        combos = []
        Solution.findCombination(candidates, [], target, combos)
        return combos
        
    def findCombination(candidates, current_list, target, combos):
        if target < 0:
            return
        
        if target == 0:
            clone = current_list[:]
            combos.append(clone)
            return
        
        for cand in candidates:
            if len(current_list) == 0 or cand >= current_list[-1]:
                current_list.append(cand)
                Solution.findCombination(candidates, current_list, target - cand, combos)
                current_list.pop()

## 2022-11-08 (iterative)
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        combinations = [[] for _ in range(target+1)]
        for c in candidates:
            if c > target:
                continue
            combinations[c].append([c])
        
        for i in range(target):
            for seq in combinations[i]:
                for c in candidates:
                    if c < seq[-1] or i+c > target:
                        continue
                    combinations[i+c].append(seq + [c])
                
        return combinations[target]