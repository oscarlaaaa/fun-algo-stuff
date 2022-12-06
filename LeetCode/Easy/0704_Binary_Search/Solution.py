from typing import *

## 2021-11-08
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0;
        right = len(nums) - 1
        
        if nums[left] == target:
            return left
        if nums[right] == target:
            return right
        
        while left < right - 1:
            mid = int((left + right) / 2)
            
            if nums[mid] > target:
                right = mid
            elif nums[mid] < target:
                left = mid
            else:
                return mid
        
        return -1

## 2022-08-29
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)-1
        while left <= right:
            mid = left + (right-left)//2
            
            if nums[mid] > target:
                right = mid-1
            elif nums[mid] < target:
                left = mid+1
            else:
                return mid
        
        return -1