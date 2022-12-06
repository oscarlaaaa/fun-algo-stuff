## 2022-05-27
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        first = version1.split(".")
        second = version2.split(".")
        
        idx1 = idx2 = 0
        while idx1 < len(first) and idx2 < len(second):
            v1, v2 = int(first[idx1]), int(second[idx2])
            if v1 > v2:
                return 1
            elif v1 < v2:
                return -1
            else:
                idx1 += 1
                idx2 += 1
        
        ## if one is longer than the other, not having only 0s remaining means its greater
        while idx1 < len(first):
            if int(first[idx1]) != 0:
                return 1
            idx1 += 1
        while idx2 < len(second):
            if int(second[idx2]) != 0:
                return -1
            idx2 += 1
        
        return 0