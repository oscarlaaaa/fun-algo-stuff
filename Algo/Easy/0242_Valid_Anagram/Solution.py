## 2022-08-17 (counting)
class Solution:
    A_ASCII = ord('a')
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        counts = [0 for _ in range(26)]
        for i in range(len(s)):
            counts[ord(s[i]) - self.A_ASCII] += 1
            counts[ord(t[i]) - self.A_ASCII] -= 1
        
        for count in counts:
            if count != 0:
                return False
        return True

## 2022-08-17 (counter class)
# 
# This solution works with unicode characters as well given that it utilizes
# a dictionary instead of a fixed-size list
#
from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count_s, count_t = Counter(s), Counter(t)
        return count_s == count_t
