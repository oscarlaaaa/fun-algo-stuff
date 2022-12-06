from typing import *

## 2022-08-17 (counting sort)
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        ## count occurrences in the array, sort,
        ## pop starting from the greatest frequencies
        ## until u reach half
        freqs = [[] for _ in range(len(arr)+1)]
        counts = Counter(arr)
        for val, count in counts.items():
            freqs[count].append(val)
    
        remain_goal = len(arr) // 2
        remain_count, set_size = len(arr), 0
        for i in range(len(freqs)-1, -1, -1):
            if remain_count <= remain_goal:
                break
            while freqs[i] and remain_count > remain_goal:
                freqs[i].pop()
                remain_count -= i
                set_size += 1
                
        return set_size
            