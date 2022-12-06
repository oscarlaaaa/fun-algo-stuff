from typing import *

## 2022-05-08
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        idx = 0
        while idx < len(s):
            count = 0
            cur_char = s[idx]
            while idx < len(s) and s[idx] == cur_char:
                count = (count+1) % k
                idx += 1
            
            if count > 0:
                if len(stack) > 0 and stack[-1][0] == cur_char:
                    stack[-1][1] = (stack[-1][1] + count) % k
                    if stack[-1][1] == 0:
                        stack.pop()
                else:
                    stack.append([cur_char, count])
            
        return "".join(c * count for c, count in stack) if stack else ""
    