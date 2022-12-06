## 2022-10-09 (unoptimized)
class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        letters = list(palindrome)
        
        ## search left to right for a char to change into 'a'
        for i in range(len(palindrome)//2):
            if palindrome[i] != 'a':
                palindrome[i] = 'a'
                return "".join(letters)

        ## search right to left for a char to increment
        for i in range(len(letters)-1, -1, -1):
            if letters[i] != 'z':
                letters[i] = chr(ord(letters[i])+1)
                return "".join(letters)

        return ""
        
## 2022-10-09 (optimized)
class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) < 2:
            return ""

        letters = list(palindrome)
        
        ## search left to right for a char to change into 'a'
        for i in range(len(letters)//2):
            if letters[i] != 'a':
                letters[i] = 'a'
                return "".join(letters)

        letters[len(palindrome)-1] = 'b'
        return "".join(letters)
        