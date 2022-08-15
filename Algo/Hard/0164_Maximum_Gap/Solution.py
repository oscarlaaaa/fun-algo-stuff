from pydoc_data.topics import topics
from string import digits
import typing
from typing import *
from math import *

## 2022-08-15 (Radix sorting)
# 
# This one was difficult to wrap my head around until I read the related topics
# and noticed it said 'Radix Sorting'. With this, you sort the values continuously
# from their least to most significant digit, maintaining order with each iteration.
# This will allow you to sort a list in O(kn) time, where K is the number of digits
# your largest value has. With a maximum possible value of 10^9, we achieve a sorting
# time of O(9n), which reduces to O(n) time complexity and an O(n) time overall.
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0
        
        cur_list = nums
        buckets = [[] for _ in range(10)]
        divisible = True
        cur_factor = 10
        
        ## radix sort using 10 buckets, one for each single digit
        while divisible:
            divisible = False
            for num in cur_list:
                ## if the val is above the current factor, we want to just
                ## put it in the first bucket and maintain order
                if int(num/(cur_factor/10)) == 0:
                    buckets[0].append(num)
                else:
                    divisible = True
                    ## remove all values before and after our desired digit
                    bucket = floor((num % cur_factor) / (cur_factor/10))
                    buckets[bucket].append(num)
            
            cur_list = [num for bucket in buckets for num in bucket]
            cur_factor *= 10
            for bucket in buckets:
                bucket.clear()
        
        largest_gap = 0
        for i in range(len(cur_list)-1):
            largest_gap = max(largest_gap, cur_list[i+1] - cur_list[i])
            
        return largest_gap
