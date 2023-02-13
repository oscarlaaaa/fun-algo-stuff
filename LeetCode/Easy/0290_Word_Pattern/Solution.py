## 2023-02-13
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        """
        input: a pattern of lowercase chars, and a string of space-separated words
        output: whether the string follows the pattern of lowercase chars

        notes:
        - can probably match words to chars using a dictionary (maybe 2 to track both ways)
            - probably need to check whether the word matches the stored pattern, or if
              the pattern matches the stored word
        - just check whether it exists in the dict and validating it for each word/char
        
        analysis:
        - time = O(n) where n=length of pattern
        - space = O(n) where n=length of pattern
        """
        n = len(pattern)

        char_word_map, word_char_map = dict(), dict()
        words = s.split(" ")
        if len(words) != n:
            return False

        for i in range(n):
            ## stored pattern char doesn't match the word
            if pattern[i] in char_word_map and words[i] != char_word_map[pattern[i]]:
                return False

            ## stored word doesn't match the pattern char
            if words[i] in word_char_map and pattern[i] != word_char_map[words[i]]:
                return False

            char_word_map[pattern[i]] = words[i]
            word_char_map[words[i]] = pattern[i]

        return True
