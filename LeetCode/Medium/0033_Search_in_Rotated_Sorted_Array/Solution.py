from typing import *
from math import *

## 2021-11-24 (find pivot first)
class Solution:
    def find_smallest_index(self, nums: List[int]) -> int:
        left = 0
        right = len(nums)-1
        smallestIndex = 0
        
        while left <= right:
            mid = ceil(left + (right - left)/2)
            
            if nums[mid] < nums[smallestIndex]:
                smallestIndex = mid
            
            if nums[mid] < nums[right]:
                right = mid-1
            else:
                left = mid+1
                
        return smallestIndex
    
    def search(self, nums: List[int], target: int) -> int:
        left = self.find_smallest_index(nums)
        right = left + len(nums)-1
        
        while left <= right:
            mid = floor(left + (right - left)/2)
            
            if nums[mid % len(nums)] > target:
                right = mid-1
            elif nums[mid % len(nums)] < target:
                left = mid+1
            else:
                return mid%len(nums)
            
        return -1

## 2022-08-29 (raw binary search)
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)-1
        while left <= right:
            mid = left + (right-left)//2
            
            if nums[mid] == target:
                return mid
            
            ## pivot on the left side of mid
            if nums[mid] < nums[left]:
                ## check if target within the sorted side (right)
                if nums[mid] <= target <= nums[right]:
                    left = mid+1
                else:
                    right = mid-1
                
            ## pivot on the right side of mid
            else:
                ## check if target within the sorted side (left)
                if nums[left] <= target <= nums[mid]:
                    right = mid-1
                else:
                    left = mid+1
                    
        return -1