from typing import *
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2022-11-08
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        start = ghost = ListNode()
        while list1 and list2:
            if list1.val < list2.val:
                ghost.next, list1 = list1, list1.next
            else:
                ghost.next, list2 = list2, list2.next
            ghost = ghost.next

        while list1:
            ghost.next, list1 = list1, list1.next
            ghost = ghost.next
        while list2:
            ghost.next, list2 = list2, list2.next
            ghost = ghost.next
        return start.next
        