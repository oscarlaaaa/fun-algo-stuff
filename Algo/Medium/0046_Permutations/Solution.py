from typing import *

## 2022-11-09 (recursive backtracking top-down with extra params)
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        output = []
        def findPerms(bag, current, output):
            if len(current) == len(bag):
                output.append(current[:])
                return
            
            for i in range(len(bag)):
                if bag[i] == 11:
                    continue
                current.append(bag[i])
                hold, bag[i] = bag[i], 11
                findPerms(bag, current, output)
                current.pop()
                bag[i] = hold
        
        findPerms(nums, [], output)
        return output

## 2022-11-09 (recursive backtracking bottom-up)
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        output = []
        for i in range(len(nums)):
            if nums[i] == 11:
                continue
            
            hold, nums[i] = nums[i], 11
            vals = self.permute(nums)
            for val in vals:
                val.append(hold)
                output.append(val)
            nums[i] = hold

        return output if output else [[]]