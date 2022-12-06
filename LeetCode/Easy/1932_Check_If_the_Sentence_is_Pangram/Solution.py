## 2022-10-16
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        seen = [False for _ in range(26)]
        for c in sentence:
            seen[ord(c)-ord('a')] = True

        return sum(seen)==26