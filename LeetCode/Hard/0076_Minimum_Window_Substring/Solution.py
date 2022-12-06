from collections import Counter

## 2022-08-29 (sliding window)
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t):
            return ""
        
        min_window = ""
        len_s = len(s)
        need, have = Counter(t), dict()
        matched, need_matched = 0, len(need)
        
        left = right = 0
        while right < len_s:
            ## expand until you have the minimum for each char
            while right < len_s and matched != need_matched:
                if s[right] in need:
                    have[s[right]] = have[s[right]]+1 if s[right] in have else 1
                    if have[s[right]] == need[s[right]]:
                        matched += 1
                        
                right += 1
            
            ## shrink until you've reached the smallest window with a solution, and record
            while left < right and matched == need_matched:
                if s[left] in need:
                    if min_window == "" or len(min_window) > right-left:
                        min_window = s[left:right]
                        
                    have[s[left]] -= 1
                    if have[s[left]] < need[s[left]]:
                        matched -= 1
                left += 1
        
        return min_window
        