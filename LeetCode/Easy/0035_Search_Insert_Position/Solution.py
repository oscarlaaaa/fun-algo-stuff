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

## 2023-02-20 (binary serach)
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        """
        input: a sorted list of distinct numbers, and a target
        output: the index of the target or where it would be if inserted

        notes:
        - simple binary search approach
        - we can probably search for the index favouring the right pointer,
          and simply returning it + 1 since right pointer would be the position
          before where it should be
        - if we don't find it during our binary search, we just need to check 
          where our l/r pointers end up and whether it is < our target (so it'd be
          pointer + 1) or > our target (where we'd insert at our pointer)
        
        analysis:
        - time = O(logn) where n=length of nums
        - space = O(1)
        """
        l, r = 0, len(nums)-1
        while l < r:
            mid = l + ceil((r-l)/2)
            if nums[mid] < target:
                l = mid
            elif nums[mid] > target:
                r = mid-1
            else:
                return mid
        return r+1 if nums[r] < target else r
        