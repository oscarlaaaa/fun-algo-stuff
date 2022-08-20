from typing import *

## 2022-08-20 (maps and sets)
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        output = []
        
        used = dict() ## keeps tracks of pairs we've matched already
        for num in nums:
            used[num] = set()
            
        seen = set() ## to skip ones we've seen already for nums[i]
        for i in range(len(nums)):
            if nums[i] in seen:
                continue
            
            need = dict()
            for j in range(i+1, len(nums)):
                if nums[j] in used[nums[i]] or nums[i] in used[nums[j]]:
                    continue
                
                if nums[j] in need:
                    output.append([nums[i], nums[j], need[nums[j]]])
                    used[nums[j]].add(nums[i])
                    used[need[nums[j]]].add(nums[i])
                else:
                    need[-nums[i] - nums[j]] = nums[j]
                
            seen.add(nums[i])
        
        return output

## 2022-08-20 (sorting + two pointer)
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        output = []
        nums.sort()
        
        i = 0
        while i < len(nums)-2:
            if i > 0 and nums[i] == nums[i-1]:
                i += 1
                continue
                
            l, r = i+1, len(nums)-1
            while l < r:
                total = nums[i] + nums[l] + nums[r]
                if total == 0:
                    output.append([nums[i], nums[l], nums[r]])
                    
                if total <= 0:
                    cur = nums[l]
                    while l < r and nums[l] == cur:
                        l += 1
                        
                if total >= 0:
                    cur = nums[r]
                    while l < r and nums[r] == cur:
                        r -= 1
            
            i += 1
        
        return output