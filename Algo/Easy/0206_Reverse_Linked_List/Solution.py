from typing import *
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2022-10-17
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, cur = None, head
        while cur:
            next_node = cur.next
            cur.next = prev
            prev, cur = cur, next_node

        return prev