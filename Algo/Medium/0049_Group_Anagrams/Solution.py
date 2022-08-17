from typing import *

## 2022-08-17
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = dict()
        for i, s in enumerate(strs):
            sorted_s = "".join(sorted(s))
            if sorted_s in anagrams:
                anagrams[sorted_s].append(i)
            else:
                anagrams[sorted_s] = [i]
        
        return [[strs[i] for i in v] for v in anagrams.values()]
        