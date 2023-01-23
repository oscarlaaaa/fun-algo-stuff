## 2022-01-02
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        trusted = set([i for i in range(1, n+1)])
        trusted_by = [0 for i in range(0, n+1)]
        
        for t in trust:
            if t[0] in trusted:
                trusted.remove(t[0])
            trusted_by[t[1]] += 1
        
        for person in trusted:
            if trusted_by[person] == n-1:
                return person
        
        return -1