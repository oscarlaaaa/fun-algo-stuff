from typing import *

## 2022-05-04 (initial solution)
class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        def summation(n) -> int:
            if n <= 0:
                return 0
            
            return (n * (n+1))//2
        
        ordered = sorted(nums)
        prev, total = 0, 0
        
        for val in ordered:
            if k == 0:
                break
                
            if val == prev:
                continue
                
            if (val - prev - 1) > k:
                total += summation(prev + k) - summation(prev)
                k = 0
            else:
                k -= val - prev - 1
                total += summation(val - 1) - summation(prev)
                prev = val
            
        if k > 0:
            total += summation(prev + k) - summation(prev)
        
        return total

## 2022-05-04 (revised after reading discussion)
class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        def summation(n) -> int:
            if n <= 0:
                return 0
            return (n * (n+1))//2
        
        ordered = sorted(set(nums))
        
        ## values already taken that we want to exclude
        exclude_sum = 0     
        
        prev = 0    ## previous value we've encountered
        for val in ordered:
            if (val - prev - 1) > k:
                prev = prev+k
                k = 0
                break
            else:
                k -= val - prev - 1
                prev = val
                exclude_sum += val
                
        return summation(prev + k) - exclude_sum
    