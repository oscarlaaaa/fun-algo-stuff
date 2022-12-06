from typing import *

## 2022-05-21
class Solution:
    def countSubstrings(self, s: str) -> int:
        def howManyPalindromes(left, right):
            count = 0
            while (left >= 0 and right < len(s) and s[left] == s[right]):
                count += 1
                left -= 1
                right += 1
            return count
        
        palindrome_count = 0
        for i in range(len(s)):
            palindrome_count += howManyPalindromes(i, i)
            if i > 0:
                palindrome_count += howManyPalindromes(i-1, i)
        
        return palindrome_count
