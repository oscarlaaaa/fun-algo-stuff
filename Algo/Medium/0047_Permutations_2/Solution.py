from typing import *

## 2022-04-27
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        def findPermutations(counts, cur_perm, perms, remain):
            if remain == 0:
                perms.append(cur_perm[:])
                return
            
            for k in counts.keys():
                if counts[k] == 0: ## skip all empty sections
                    continue
                    
                ## append and backtrack after finished exploring
                cur_perm.append(k)
                counts[k] -= 1
                findPermutations(counts, cur_perm, perms, remain-1)
                
                cur_perm.pop(-1)
                counts[k] += 1
            
        counts = dict()
        for num in nums:
            counts[num] = counts[num]+1 if num in counts else 1
        
        perms = []
        findPermutations(counts, [], perms, len(nums))
        return perms

## 2022-05-11
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        counts = dict()
        for num in nums:
            counts[num] = counts[num]+1 if num in counts else 1
        
        permutations = []
        self.permute([], counts, permutations)
        return permutations
        
    def permute(self, current, remaining, permutations):
        if len(remaining) == 0:
            permutations.append(current[:])
        
        keys = list(remaining.keys())
        for key in keys:
            remaining[key] -= 1
            if remaining[key] == 0:
                del remaining[key]
            current.append(key)

            self.permute(current, remaining, permutations)
            
            remaining[key] = remaining[key]+1 if key in remaining else 1
            current.pop()
            
            