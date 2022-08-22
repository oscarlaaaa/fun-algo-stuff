from typing import *

## 2021-11-29 (two pointer)
class Solution:
    def maxArea(self, height: List[int]) -> int:
        total_max = 0
        
        left = 0
        right = len(height)-1
        
        while left < right:
            shorter_height = min(height[left], height[right])
            current_max = (right - left)*shorter_height
            total_max = max(total_max, current_max)
            
            if height[left] < height[right]:
                left += 1
            elif height[right] < height[left]:
                right -= 1
            else:
                left += 1
                right -= 1
        
        return total_max

## 2022-04-05 (two pointer)
class Solution:
    def maxArea(self, height: List[int]) -> int:
        # input - list of heights
        # output - maximum area possible that we can fill w/ water
        
        # stack
        # two pointers?
        #  - start at either end
        #  - keep track of tallest at either end + maximum area so far
        #  - increment the shorter one until you find a taller wall
        
        left, right = (0, len(height)-1)
        max_water: int = 0
        while left < right:
            max_water = max(max_water, min(height[left], height[right])*(right-left))
            if height[left] < height[right]:
                left += 1
            elif height[left] > height[right]:
                right -= 1
            else:
                left += 1
                right -= 1
        return max_water

## 2022-08-21 (stack solution)
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l_to_r = []
        r_to_l = []
        for i, h in enumerate(height):
            if not l_to_r or h > height[l_to_r[-1]]:
                l_to_r.append(i)
        for i, h in reversed(list(enumerate(height))):
            if not r_to_l or h > height[r_to_l[-1]]:
                r_to_l.append(i)
        
        maximum = 0
        while l_to_r and r_to_l:
            w = max(l_to_r[-1], r_to_l[-1]) - min(l_to_r[-1], r_to_l[-1])
            h = min(height[l_to_r[-1]], height[r_to_l[-1]])
            maximum = max(maximum, w*h)
            
            if len(l_to_r) == 1:
                r_to_l.pop()
            elif len(r_to_l) == 1:
                l_to_r.pop()
            else:
                if height[l_to_r[-2]] > height[r_to_l[-2]]:
                    l_to_r.pop()
                else:
                    r_to_l.pop()
        
        return maximum
            