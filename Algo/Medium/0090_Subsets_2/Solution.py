from typing import *

## 2022-11-09 (iterative)
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        counts = dict()
        for num in nums:
            counts[num] = counts.get(num, 0)+1
        
        subsets = [[]]
        for num in range(-10, 11):
            n = len(subsets)
            for _ in range(counts.get(num, 0)):
                additional = []
                for k in range(1, n+1):
                    additional.append(subsets[-k] + [num])
                subsets += additional
        
        return subsets
