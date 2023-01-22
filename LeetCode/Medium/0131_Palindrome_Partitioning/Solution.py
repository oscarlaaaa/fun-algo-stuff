## 2022-01-05
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        final = []
        self.search(s, 0, 0, [], final)
        return final
    
    def search(self, s: str, start: int, pos: int, track: List[str], total: List[List[str]]):
        if start >= len(s):
            copy = track[:]
            total.append(copy)
        
        while pos <= len(s):
            if pos - start > 0 and Solution.is_palindrome(s[start:pos]):
                track.append(s[start:pos])
                self.search(s, pos, pos+1, track, total)
                track.pop()
            pos += 1
        
        
    def is_palindrome(s: str) -> bool:
        left = 0
        right = len(s)-1
        
        while left < right:
            if s[left] != s[right]:
                return False
            
            left += 1
            right -= 1
        
        return True