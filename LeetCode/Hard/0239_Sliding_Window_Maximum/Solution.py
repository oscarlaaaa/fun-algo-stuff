from collections import deque
from typing import *

## 2022-10-22 (monotonic deque)
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        window = deque()
        output = []
        
        for i, val in enumerate(nums):
            while window and window[0]+k <= i:
                window.popleft()
            
            while window and nums[window[-1]] < val:
                window.pop()
            
            window.append(i)

            if i >= k-1:
                output.append(nums[window[0]])
        
        return output
            