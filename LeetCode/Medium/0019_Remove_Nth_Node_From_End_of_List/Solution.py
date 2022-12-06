from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2022-10-24
#
# input: a LL, a value for the nth node from the end of the list to return
# output: the head of the list after removal
#
# approach:
# - have a scout node that is n ahead of our current that determines when we are n from the end
# - iterate until scout node is 0, then remove the node of cur
# - return whatever ghost is pointing to next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        ghost = ListNode(-1, head)
        prev, cur, scout = ghost, head, head
        for i in range(n):
            scout = scout.next
        
        while scout:
            prev, cur = cur, cur.next
            scout = scout.next
        
        prev.next = cur.next
        return ghost.next
