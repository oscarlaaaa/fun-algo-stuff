from typing import *

## 2022-10-26 (prefix-sum plus two-sum)
#
# We first create a prefix sum array using the original array in order to
# easily calculate the sums of various subarrays(prefix_sum[right] - prefix_sum[left-1]).
# Then, we parse through the prefix sum array, taking the modulus k of each value and checking
# for its existence within our set, and storing the modulus of the prefix sum 2 spaces prior
# within our set.
#
# The reason we look for matching modulus k values within our prefix sum is because if 
# we have two values that have the same modulus value, then that means the gap between them
# has to be a multiple of K as it would change the modulus value otherwise.
#
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        for i in range(1, n):
            nums[i] += nums[i-1]
        
        need = set([0])
        for i in range(1, n):
            if i >= 2:
                need.add(nums[i-2]%k)

            if nums[i]%k in need:
                return True

        return False
    