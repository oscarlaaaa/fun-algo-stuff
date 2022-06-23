from heapq import *
from typing import *

## 2022-06-22 
class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:  
        bricks_used = []
        remaining_bricks = bricks
        remaining_ladders = ladders
        for i in range(len(heights)):
            if i == len(heights)-1:
                return i
            
            height_diff = heights[i+1] - heights[i]

            ## if next building is the same height or lower, we can just continue
            if height_diff <= 0:
                continue
                
            if remaining_bricks >= height_diff:
                remaining_bricks -= height_diff
                heappush(bricks_used, -height_diff)
            else:
                ## if using a ladder previously would have saved more bricks, then lose a ladder and
                ## gain back the difference
                if bricks_used and height_diff < -bricks_used[0] and remaining_ladders > 0:
                    remaining_bricks += -heappop(bricks_used) - height_diff
                    remaining_ladders -= 1
                    heappush(bricks_used, -height_diff)
                elif remaining_ladders > 0:
                    remaining_ladders -= 1
                else:
                    return i

        return -1