from typing import *

## 2021-11-08 (python hack)
# 
# This solution is shorter and (probably) more pythonic, but has the detriment of
# having to iterate through the whole list to convert it into a set before being
# able to return a value.
#
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) < len(nums)

## 2022-08-17 (basic)
# 
# This solution has the benefit of being easy to read, and being able to exit early
# if a duplicate is found.
#
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        for num in nums:
            if num in seen:
                return True
            seen.add(num)
        return False
    