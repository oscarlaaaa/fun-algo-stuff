from typing import *

## 2022-09-19 (2 pointer)
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        to_remove, to_keep = 0, 0
        n = len(nums)
        
        ## swap left-vals to remove with right-vals to keep
        while to_remove < n and to_keep < n:
            if nums[to_remove] != val:
                to_remove += 1
            elif nums[to_keep] == val or to_keep <= to_remove:
                to_keep += 1
            else:
                nums[to_remove], nums[to_keep] = nums[to_keep], nums[to_remove]

        ## remove all vals to remove
        while nums and nums[-1] == val:
            nums.pop()
        
        return len(nums)
        
        