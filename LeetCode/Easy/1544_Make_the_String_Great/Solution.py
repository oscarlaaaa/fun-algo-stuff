## 2022-11-07 (stack approach)
class Solution:
    def makeGood(self, s: str) -> str:
        diff = abs(ord('A') - ord('a'))
        output = []
        for c in s:
            if output and abs(ord(output[-1]) - ord(c)) == diff:
                output.pop()
            else:
                output.append(c)
                        
        return "".join(output)