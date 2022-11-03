from typing import *

## 2022-11-02 (hashmap)
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        """
        input = list[string] words (2 lowercase letters each)
        output: longest possible palindrome we can output

        constraints:
        - duplicates in words is allowed
        - words can only palindrome their mirror image (lc with cl)

        observations
        - need either a symmetrical word in the center, or none
        - keep a count of how many pairs of letters we have
        - pair = length of 4

        approach:
        - iterate through our array, and add count to the mirror version of the word in our dict
        - if a word exists in our dict, remove and add 4 to our length
        - after we finish, iterate through set for an unmatched pair like "gg"
            - if we find, add 2 to output

        """
        length = 0
        need = dict()
        for word in words:
            if word in need and need[word] > 0:
                need[word] -= 1
                length += 4
            else:
                rev_word = word[::-1]
                need[rev_word] = need.get(rev_word, 0)+1
        
        for word, count in need.items():
            if word[0] == word[1] and count > 0: 
                return length + 2
        
        return length
        