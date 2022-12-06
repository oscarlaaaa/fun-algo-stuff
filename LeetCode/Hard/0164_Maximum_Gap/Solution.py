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


## 2022-08-15 (Bucket sort)
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        min_val, max_val = min(nums), max(nums)
        
        if min_val == max_val or len(nums) < 2:
            return 0
        
        ## each bucket will hold a range of vals and buckets will
        ## only store min and max of each range
        bucket_size = ceil((max_val - min_val) / (len(nums)-1))
        buckets = [[inf, -inf] for _ in range(len(nums))]
        
        for num in nums:
            bucket_idx = (num - min_val)//bucket_size
            buckets[bucket_idx][0] = min(buckets[bucket_idx][0], num)
            buckets[bucket_idx][1] = max(buckets[bucket_idx][1], num)
        
        buckets = [bucket for bucket in buckets if bucket[0] != inf]
        
        largest_gap = bucket_size
        for i in range(len(buckets)-1):
            largest_gap = max(largest_gap, buckets[i+1][0] - buckets[i][1])
            
        return largest_gap
        