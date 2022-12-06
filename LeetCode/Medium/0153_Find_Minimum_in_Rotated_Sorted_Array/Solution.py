from typing import *
from math import floor

## 2022-11-24
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)-1
        smallest = min(nums[left], nums[right])
        
        while left <= right:
            mid = floor(left + (right - left)/2)
            
            smallest = min(smallest, nums[mid])
            
            if nums[mid] < nums[right]:
                right = mid-1
            else:
                left = mid+1
                
        return smallest