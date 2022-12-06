from collections import *

## 2022-08-16 (queue)
class Solution:
    def firstUniqChar(self, s: str) -> int:
        seen = dict()
        queue = deque()
        
        for i, c in enumerate(s):
            if c not in seen or seen[c] < 2:
                queue.append(i)
                seen[c] = seen[c] + 1 if c in seen else 1
            
            while queue and seen[s[queue[0]]] >= 2:
                queue.popleft()
        
        return queue[0] if queue else -1
    

## 2022-08-16 (two-pass)
class Solution:
    def firstUniqChar(self, s: str) -> int:
        seen = dict()
        for c in s:
            seen[c] = seen[c]+1 if c in seen else 1
        
        for i, c in enumerate(s):
            if seen[c] < 2:
                return i
            
        return -1
    
