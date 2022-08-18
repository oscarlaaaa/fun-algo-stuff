from typing import *

## 2022-05-11
class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleaned = "".join(c for c in s if c.isalnum()).lower()
        left, right = 0, len(cleaned)-1
        
        while left < right and cleaned[left] == cleaned[right]:
            left += 1
            right -= 1
        
        return left >= right

## 2022-08-18
class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleaned = [c.lower() for c in s if c.isalnum()]
        for i in range(0, len(cleaned)//2):
            if cleaned[i] != cleaned[-i-1]:
                return False
        return True