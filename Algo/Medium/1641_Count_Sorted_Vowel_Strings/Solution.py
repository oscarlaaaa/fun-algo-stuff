## 2022-05-10
class Solution:
    def countVowelStrings(self, n: int) -> int:
        counts = [1, 1, 1, 1, 1]  # [a, e, i, o, u]
        for _ in range(2, n+1):
            for j in range(len(counts)-1):
                counts[j+1] += counts[j]
        return sum(counts)
