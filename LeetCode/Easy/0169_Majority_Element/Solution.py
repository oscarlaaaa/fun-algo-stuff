from typing import *

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cur_majority = nums[0]
        count = 0
        
        for num in nums:
            if cur_majority == num:
                count += 1
            else:
                if count == 0:
                    cur_majority = num
                else:
                    count -= 1
        
        return cur_majority