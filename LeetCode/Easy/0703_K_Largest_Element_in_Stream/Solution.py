## 2022-11-09 (min-heap)
from typing import *
import heapq
class KthLargest:
    """
    approach:
    - min heap, only holding k values at a time
    """

    def __init__(self, k: int, nums: List[int]):
        self._heap = []
        self._limit = k
        for num in nums:
            heapq.heappush(self._heap, num)
            if len(self._heap) > k:
                heapq.heappop(self._heap)

    def add(self, val: int) -> int:
        heapq.heappush(self._heap, val)
        if len(self._heap) > self._limit:
            heapq.heappop(self._heap)
        return self._heap[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)