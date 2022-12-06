from typing import *

## 2021-11-24
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row = 0;
        while matrix[row][-1] < target:
            row = row + 1
            if row == len(matrix):
                return False
        
        left = 0
        right = len(matrix[row])-1
        while left <= right:
            mid = floor(left + (right - left)/2)
            
            if matrix[row][mid] > target:
                right = mid-1
            elif matrix[row][mid] < target:
                left = mid+1
            else:
                return True
            
        return False

## 2022-03-29
from math import *
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        up = 0
        down = len(matrix)-1
        col = -1
        while up <= down:
            mid = down + floor((up - down)/2)
            if matrix[mid][0] <= target <= matrix[mid][len(matrix[mid])-1]:
                col = mid
                break
            if target < matrix[mid][0]:
                down = mid-1
            if target > matrix[mid][len(matrix[mid])-1]:
                up = mid+1
        
        if col == -1:
            return False
        
        left = 0
        right = len(matrix[col])-1
        while left <= right:
            mid = left + floor((right - left)/2)
            if matrix[col][mid] < target:
                left = mid+1
            elif matrix[col][mid] > target:
                right = mid-1
            else:
                return True
        return False
        

## 2022-08-29 (double binary search)
class Solution:
    def findRow(self, matrix, target) -> int:
        ## find the row
        top, bot = 0, len(matrix)-1
        while top <= bot:
            row = top + (bot-top)//2
            
            if target < matrix[row][0]:
                bot = row-1
            elif target > matrix[row][-1]:
                top = row+1
            else:
                return row
        
        return -1
        
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row = self.findRow(matrix, target)
        if row == -1:
            return False
        
        left, right = 0, len(matrix[row])
        while left <= right:
            mid = left + (right-left)//2
            
            if target < matrix[row][mid]:
                right = mid-1
            elif target > matrix[row][mid]:
                left = mid+1
            else:
                return True
        
        return False
                