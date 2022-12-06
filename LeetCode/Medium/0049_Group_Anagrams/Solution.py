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

## 2022-10-29 (hashing with tuples)
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def build_tuple(s):
            output = [0 for _ in range(26)]
            a = ord('a')
            for c in s:
                output[ord(c) - a] += 1
            return tuple(output)
            
        groups = dict()
        for s in strs:
            t = build_tuple(s)
            if t not in groups:
                groups[t] = []
            groups[t].append(s)
        return [anagrams for anagrams in groups.values()]
