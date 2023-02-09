## 2022-03-01 (greedy)
import math

class Solution:
    def jump(self, nums: List[int]) -> int:
        goal = len(nums)-1
        jumps, cur = (0, 0)
        
        while cur < len(nums)-1:
            farthest_space = nums[cur] + cur
            
            ## if goal is reachable, jump onto the goal
            if farthest_space >= goal:
                cur = goal
            else:
                max_dist = nums[cur]
                max_index = cur + nums[cur]
                
                # search for next reachable space that reaches the farthest
                for i in range(cur+1, farthest_space + 1):
                    if i + nums[i] > max_dist:
                        max_dist = i + nums[i]
                        max_index = i
                cur = max_index
                
            jumps += 1
        return jumps