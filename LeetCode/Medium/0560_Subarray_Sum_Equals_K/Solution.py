from typing import *

## 2022-10-26 (prefix sum + twosum approach)
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_sum = nums[:]
        for i in range(1, len(nums)):
            prefix_sum[i] += prefix_sum[i-1]
        
        need = dict()
        count = 0
        for val in prefix_sum:
            if val == k:
                count += 1
            if val in need:
                count += need[val]
            need[k+val] = need[k+val]+1 if k+val in need else 1
        
        return count