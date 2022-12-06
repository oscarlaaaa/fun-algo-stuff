from typing import *

## 2022-08-22 (monotonic stack)
class Solution:
    def trap(self, height: List[int]) -> int:
        ## stack of heights (highest to lowest)
        ## - if you encounter a lower height, append height + index on
        ## - if you encounter a higher height, pop off and find volumes until either
        ##   stack is empty or you run into a height greater than the current
        stack = []
        volume = 0
        for i, h in enumerate(height):
            while stack and stack[-1][1] <= h:
                floor = stack[-1][1]
                stack.pop()

                if stack:
                    volume += (i-stack[-1][0]-1) * (min(h, stack[-1][1])-floor)
                        
            stack.append((i, h))
        
        return volume

## 2022-08-22 (multi-pass)
# 
# For this solution, we only want to check if the current cell has higher heights
# on either side of it, regardless of how far they are. If the current cell has a
# lower height than the cells to the left/right of it, we know that it would be 
# filled up by the minimum of the left/right highest cells - the current height.
# As such, we build a left_max and a right_max list for each cell to check if there
# are cells to the current cell's left and right that are taller than it.
#
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left_max = [0 for _ in range(n)]
        right_max = [0 for _ in range(n)]
        
        for i in range(1, n):
            left_max[i] = max(left_max[i-1], height[i-1])
        for i in range(n-2, -1, -1):
            right_max[i] = max(right_max[i+1], height[i+1])
        
        volume = 0
        for i in range(n):
            if left_max[i] > height[i] and right_max[i] > height[i]:
                volume += min(left_max[i], right_max[i]) - height[i]
        
        return volume