from typing import *
from math import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2022-01-31 (Mergesort styled solution)
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        k = len(lists)        
        if k == 0:
            return None
        merged = Solution.mergeLists(lists, 0, k-1)
        return merged
    
    def mergeLists(lists, start, end):
        if end - start < 0:
            return None
        
        if end - start == 0:
            return lists[start]
        
        if end - start == 1:
            return Solution.merge(lists[start], lists[end])
        
        if end - start > 1:
            return Solution.merge(Solution.mergeLists(lists, start, start+floor((end-start)/2)), \
                                  Solution.mergeLists(lists, start+floor((end-start)/2)+1, end))
        
    def merge(nodesA, nodesB):
        if nodesA is None or nodesB is None:
            return nodesA if nodesA else nodesB
        
        merged = None
        merged_head = None
        while nodesA or nodesB:
            if merged is None:
                merged = nodesA if nodesA.val < nodesB.val else nodesB
                merged_head = merged
            else:
                if nodesA is None or nodesB is None:
                    merged.next = nodesA if nodesA else nodesB
                    break
                else:
                    merged.next = nodesA if nodesA.val < nodesB.val else nodesB
                    merged = merged.next
                    
            if nodesA.val < nodesB.val:
                nodesA = nodesA.next
            else:
                nodesB = nodesB.next        
                
        return merged_head