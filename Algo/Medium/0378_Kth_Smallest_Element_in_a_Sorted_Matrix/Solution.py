import heapq
from typing import *

## 2022-08-16 (k-heap approach)
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        heap = []
        for row in matrix:
            for cell in row:
                ## prevents us from pushing a value we'd just pop immediately
                if len(heap) < k or -cell > heap[0]:
                    heapq.heappush(heap, -cell)
                
                ## maintain k-size heap
                if len(heap) > k:
                    heapq.heappop(heap)
        
        return -heap[0]
                