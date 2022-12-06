from typing import List

## 2022-09-13
#
# one main rule to follow to guarantee a valid parentheses set:
# - you can only place a right bracket if there are less rights than lefts
# 
# as long as you follow this rule, all permutations should be valid.
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def generatePerms(remainL, remainR, cur, perms):
            if remainL == remainR == 0:
                perms.append(''.join(cur))
                return
            
            if remainL > 0:
                cur.append('(')
                generatePerms(remainL-1, remainR, cur, perms)
                cur.pop()
            
            if remainR > remainL:
                cur.append(')')
                generatePerms(remainL, remainR-1, cur, perms)
                cur.pop()
        
        cur, perms = [], []
        generatePerms(n, n, cur, perms)
        return perms