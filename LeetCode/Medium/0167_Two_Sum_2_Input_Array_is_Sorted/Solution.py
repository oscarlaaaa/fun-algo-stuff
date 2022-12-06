from typing import *

## 2022-08-18 (two pointer)
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        lo, hi = 0, len(numbers)-1
        
        while lo < hi and numbers[lo] + numbers[hi] != target:
            if numbers[lo] + numbers[hi] < target:
                lo += 1
            else:
                hi -= 1
        
        return [lo+1, hi+1]

## 2022-08-18 (memo)
#
# this lowkey defeats the purpose of the question but...
#
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        memo = dict()
        for i, num in enumerate(numbers):
            if num in memo:
                return [memo[num]+1, i+1]
            else:
                memo[target-num] = i
        return [-1, -1]
        