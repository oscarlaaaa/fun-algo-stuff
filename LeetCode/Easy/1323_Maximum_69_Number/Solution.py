## 2022-11-06
class Solution:
    def maximum69Number (self, num: int) -> int:
        val = list(str(num))
        for i in range(len(val)):
            if val[i] == '6':
                val[i] = '9'
                break
        
        return int("".join(val))