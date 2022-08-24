## 2022-08-23 (check every char)
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        length = len(s)
        check = set(s)
        max_length = 0
        
        for c in check:
            left = right = 0
            replace = k
            while right < length:
                if s[right] != c:
                    replace -= 1
                
                while replace < 0:
                    if s[left] != c:
                        replace += 1
                    left += 1
                
                right += 1
                max_length = max(max_length, right-left)
                
        return max_length
                
## 2022-08-24 (sliding windww)
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        length = len(s)
        max_f, max_length = 0, 0
        left, right = 0, 0
        counts = dict()
        
        while right < length:
            if s[right] not in counts:
                counts[s[right]] = 0
                
            counts[s[right]] += 1
            max_f = max(max_f, counts[s[right]])
            right += 1
            
            while right-left-max_f > k:
                counts[s[left]] -= 1
                left += 1
                
            max_length = max(max_length, right-left)
            
        return max_length

                    
            
            