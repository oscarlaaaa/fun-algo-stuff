from typing import *

## 2022-05-08
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        combos = [[], [], ['a', 'b', 'c'], \
                    ['d', 'e', 'f'], \
                    ['g', 'h', 'i'], \
                    ['j', 'k', 'l'], \
                    ['m', 'n', 'o'], \
                    ['p', 'q', 'r', 's'], \
                    ['t', 'u', 'v'], \
                    ['w', 'x', 'y', 'z']]
                 
        
        cur_combos = []
        
        for d in digits:
            if len(cur_combos) == 0:
                cur_combos = [c for c in combos[int(d)]]
            else:
                new_combos = []
                for combo in cur_combos:
                    for c in combos[int(d)]:
                        new_combos.append(combo + c)
                cur_combos = new_combos
        
        return cur_combos
    