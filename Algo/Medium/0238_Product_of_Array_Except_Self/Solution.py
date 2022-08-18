from typing import *

## 2021-11-28
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        lr = [1] * len(nums)
        rl = [1] * len(nums)
        
        for i in range(0, len(nums)-1):
            lr[i+1] = lr[i] * nums[i]
        for j in range(len(nums)-1, 0, -1):
            rl[j-1] = rl[j] * nums[j]
                
        output = []
        for i in range(0, len(nums)):
            output.append(lr[i]*rl[i])
        
        return output


## 2022-08-18 
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output = [1 for _ in nums]
        prefix_prod = 1
        for i in range(len(nums)):
            output[i] *= prefix_prod
            prefix_prod *= nums[i]
        
        prefix_prod = 1
        for i in range(len(nums)-1, -1, -1):
            output[i] *= prefix_prod
            prefix_prod *= nums[i]
        
        return output