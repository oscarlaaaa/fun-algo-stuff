from collections import Counter

## 2022-08-29 (sliding window)
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        counts = Counter(s1)
        need = counts.copy()
        length = len(s2)
        
        left = right = 0
        while right < length:
            ## reset pointers to a useful starting position if right char is not useful
            if s2[right] not in counts:
                while right < length and s2[right] not in counts:
                    right += 1
                need = counts.copy()
                left = right
                
            ## decrementing and removing needed chars
            elif s2[right] in need:
                need[s2[right]] -= 1
                if need[s2[right]] == 0:
                    del need[s2[right]]
                right += 1
                
            ## re-increment chars if we've run into a useful one without sufficient space
            else:
                need[s2[left]] = need[s2[left]]+1 if s2[left] in need else 1
                left += 1
                
            if len(need) == 0:
                return True
        
        return False
