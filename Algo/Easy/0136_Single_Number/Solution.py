from typing import *

## 2022-02-15
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        single = 0
        for num in nums:
            single = single ^ num
        return single