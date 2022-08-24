## 2022-08-23 (sliding window)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        length = len(s)
        
        contains = set()
        left, right = 0, 0
        while right < length:
            ## add values to window until we've run into a repeat
            if s[right] not in contains:
                contains.add(s[right])
                right += 1
            
            longest = max(longest, right - left)
            
            ## remove values from window until we've removed the repeat
            if right < length and s[right] in contains:
                contains.remove(s[left])
                left += 1
        
        return longest