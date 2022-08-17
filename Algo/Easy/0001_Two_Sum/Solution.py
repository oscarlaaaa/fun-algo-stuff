from typing import *

class Solution:
    # 2020-11-22
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for x in range(i+1, len(nums)):
                if nums[i] + nums[x] == target:
                    return [i, x]
    
    # 2021-09-16
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        output = []
        
        for i in range(0, len(nums)):
            if nums[i] in dict:
                output.append(dict[nums[i]])
                output.append(i)
                break
            else:
                dict[target - nums[i]] = i
        
        return output
    
    # 2021-11-23
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = dict()
        
        for i in range(0, len(nums)):
            if nums[i] in dic:
                return [dic[nums[i]], i]
            else:
                dic[target - nums[i]] = i
        
        return None
    
    # 2022-08-17
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        need = dict()
        for i, num in enumerate(nums):
            if num in need:
                return [i, need[num]]
            need[target-num] = i
        return [-1, -1]
    