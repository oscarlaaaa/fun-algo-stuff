## 2022-04-13
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        # generate the count of chars we need
        need = dict()
        for c in p:
            need[c] = need[c]+1 if c in need else 1
            
        output = []
        cur_need = need.copy() # what we need currently
        left, right = 0, 0
        while right < len(s):
            if s[right] in need:
                while s[right] not in cur_need:
                    cur_need[s[left]] = cur_need[s[left]]+1 if s[left] in cur_need else 1
                    left += 1
                    
                cur_need[s[right]] -= 1
                if cur_need[s[right]] == 0:
                    del cur_need[s[right]]
                    
                if len(cur_need) == 0:
                    output.append(left)
                    
            else:
                left = right+1
                cur_need = need.copy()
            
            right += 1
            

        return output