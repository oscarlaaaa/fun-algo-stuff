from typing import *
from functools import *
import math

## 2022-05-04 (TLE)
class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        if len(nums) == 1:
            return nums
        
        @cache
        def gcd(x, y):
            return math.gcd(x, y)
        
        @cache
        def lcm(x, y):
            return math.lcm(x, y)

        starting = 1
        no_adjacent = True
        while no_adjacent:
            no_adjacent = False
            if len(nums) <= 1:
                break
            i = starting if starting > 0 else 1
            while i < len(nums):
                if gcd(nums[i-1], nums[i]) > 1:
                    if not no_adjacent:
                        starting = i-1
                    calculated = set([nums[i-1], nums[i]])
                    nums[i] = lcm(nums[i-1], nums[i])
                    nums[i-1] = -1
                    while i+1 < len(nums) and nums[i+1] in calculated:
                        nums[i+1] = nums[i]
                        nums[i] = -1
                        i += 1
                    no_adjacent = True
                i += 1
            nums = [val for val in nums if val != -1]
                
        return nums
                