from typing import *
## 2022-05-01
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        left, right = 0, len(nums)-1
        while left < right:
            while left < right and nums[left] & 1 == 0: # increment left until val is odd
                left += 1
            while right > left and nums[right] & 1 == 1: # decrement right until val is even
                right -= 1
                
            if left >= right:
                break
            
            nums[left], nums[right] = nums[right], nums[left] ## swapperino
        
        return nums