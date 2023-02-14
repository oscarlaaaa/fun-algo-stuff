## 2023-02-13
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        """
        input: string a, and string b binary strings
        output: an output binary string

        notes:
        - can probably add bit by bit normally?
            - tracking whether we need to carry a value forward or not
        - would pushing into a list -> joining be more efficient than just
          repeatedly strign concatenating? probably
            - jk not really at all
        
        analysis:
        - time = O(n) where n=longest string
        - space = O(1) not including output string
        """
        output = ""
        carry = 0
        i, j = 1, 1
        m, n = len(a), len(b)
        while i <= m or j <= n:
            total = carry
            if i <= m:
                total += int(a[-i])
                i += 1
            if j <= n:
                total += int(b[-j])
                j += 1
            carry = total // 2
            output = str(total % 2) + output
        
        if carry == 1:
            output = '1' + output

        return output
        