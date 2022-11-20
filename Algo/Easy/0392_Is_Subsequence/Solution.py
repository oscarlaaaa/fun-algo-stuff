## 2022-03-02
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) > len(t):
            return False
        
        remaining_string = t
        
        for char in s:
            idx = remaining_string.find(char)
            if idx == -1:
                return False
            remaining_string = remaining_string[idx+1:]
        
        return True