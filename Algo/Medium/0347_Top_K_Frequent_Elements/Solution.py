from typing import *

## 2022-04-13 (sorting)
#
# We count all the occurrences, and essentially do a bucket-sort
# of the values to achieve an O(n) time complexity
#
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = dict()
        for num in nums:
            counts[num] = counts[num]+1 if num in counts else 1
        
        freqs = [[] for _ in range(len(nums)+1)]
        
        for key, val in counts.items():
            freqs[val].append(key)
        
        output = []
        for freq in reversed(freqs):
            output += freq
        
        return output[:k]


## 2022-08-17 (k-heap)
#
# Because the heap never exceeds size K, you end up with a time complexity of
# O(nlogk).
# 
from collections import Counter
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)
        top_k = []
        
        for val, count in counts.items():
            heapq.heappush(top_k, (count, val))
            if len(top_k) > k:
                heapq.heappop(top_k)
                
        return [count[1] for count in top_k]        

## 2022-08-17 (bucket sort)
from itertools import chain
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequencies = [[] for _ in range(len(nums)+1)]
        counts = Counter(nums)
        
        for val, count in counts.items():
            frequencies[count].append(val)
        
        sorted_freqs = list(chain.from_iterable(frequencies))
        return sorted_freqs[-k:]
    
    