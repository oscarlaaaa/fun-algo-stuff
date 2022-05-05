from typing import *

## 2022-05-04
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        arr = []
        idx1 = idx2 = 0
        while idx1 < m and idx2 < n:
            if nums1[idx1] < nums2[idx2]:
                arr.append(nums1[idx1])
                idx1 += 1
            else:
                arr.append(nums2[idx2])
                idx2 += 1
        
        while idx1 < m:
            arr.append(nums1[idx1])
            idx1 += 1
        while idx2 < n:
            arr.append(nums2[idx2])
            idx2 += 1
        
        for i in range(n+m):
            nums1[i] = arr[i]
                    