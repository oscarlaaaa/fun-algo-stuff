from math import *
from typing import *

## 2021-11-25
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        
        if len(nums) == 0:
            return 0
        
        low = 0
        high = len(nums)-1
        
        while low < high:
            mid = floor(low + (high-low)/2)
            
            if nums[mid] > target:
                high = mid-1
            elif nums[mid] < target:
                low = mid+1
            else:
                return mid
        
        if target <= nums[low]:
            return low
        elif target > nums[low]:
            return low+1
            