## 2022-07-14 (iterative DP approach)
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        indices = dict()
        for i, c in reversed(list(enumerate(t))):
            if c in indices:
                indices[c].append(i)
            else:
                indices[c] = [i]
        
        reached = [0 for i in range(len(t)+1)]
        reached[-1] = 1
        for i, c in enumerate(s):
            if c in indices:
                for idx in indices[c]:
                    reached[idx] += reached[idx-1]
                    
        return reached[-2]