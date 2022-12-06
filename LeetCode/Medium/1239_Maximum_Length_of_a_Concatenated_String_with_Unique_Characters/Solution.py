from typing import *

## 2022-10-24 (backtracking)
# input = array of strings
# output = longestp possible length of concatenated strings with unique charcaters
# summary: find as many strings while maintaining unique charcaters as possible
# approach:
# - create a set for every word in arr
# - backtracking? while maintaining max
# - will end up with O(2^n) solution i think as each option is either include or not, which is exponential
#     - should be okay because we have an upper limit of 16 words, 26 chars
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def findLongest(arr, idx, current_chars):
            if idx >= len(arr):
                return len(current_chars)
            
            # skip current word
            longest = findLongest(arr, idx+1, current_chars)

            # take current word if able to
            for i, c in enumerate(arr[idx]):
                if c in current_chars:
                    # remove all already-added
                    for j in range(i-1, -1, -1):
                        current_chars.remove(arr[idx][j])
                    return longest
                current_chars.add(c)
            
            longest = max(longest, findLongest(arr, idx+1, current_chars))
            for c in arr[idx]:
                current_chars.remove(c)
            return longest

        current_chars = set()
        return findLongest(arr, 0, current_chars)

## 2022-10-24 (same as above except with set operations)
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def findLongest(arr, idx, current_chars):
            if idx >= len(arr):
                return len(current_chars)
            
            cur_word = set(arr[idx])
            if len(cur_word) != len(arr[idx]):
                return findLongest(arr, idx+1, current_chars)
            
            # skip current word
            longest = findLongest(arr, idx+1, current_chars)

            # take current word if able to
            if cur_word & current_chars:
                return longest
            
            current_chars = current_chars | cur_word
            longest = max(longest, findLongest(arr, idx+1, current_chars))
            current_chars = current_chars - cur_word

            return longest

        return findLongest(arr, 0, set())
