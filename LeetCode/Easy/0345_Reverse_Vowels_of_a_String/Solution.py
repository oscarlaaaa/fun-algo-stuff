## 2022-11-03
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = set("AaEeIiOoUu")
        string = list(s)
        left, right = 0, len(s)-1

        while left < right:
            if string[left] not in vowels:
                left += 1
            elif string[right] not in vowels:
                right -= 1
            else:
                string[left], string[right] = string[right], string[left]
                left += 1
                right -= 1
        
        return "".join(string)