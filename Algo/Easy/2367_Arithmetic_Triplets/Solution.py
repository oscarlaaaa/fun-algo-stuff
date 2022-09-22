from typing import *

## 2022-09-22 (O(n) lets goooo)
class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        count = 0
        want = set()
        pairs = set()
        for num in nums:
            if (num-2*diff, num-diff) in pairs:
                count += 1
            if num in want:
                pairs.add((num-diff, num))
            want.add(num+diff)
        return count
    