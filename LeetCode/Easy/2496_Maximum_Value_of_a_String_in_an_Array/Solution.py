from typing import *

## 2022-12-10
class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        return max([int(x) if x.isnumeric() else len(x) for x in strs])