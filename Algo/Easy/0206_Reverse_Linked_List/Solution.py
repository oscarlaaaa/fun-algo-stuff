from typing import *
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2022-10-17 (iterative)
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, cur = None, head
        while cur:
            next_node = cur.next
            cur.next = prev
            prev, cur = cur, next_node

        return prev

## 2022-10-17 (recursive)
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def rev(prev, cur):
            if not cur:
                return prev
            next_node = cur.next
            cur.next = prev
            return rev(cur, next_node)
        
        return rev(None, head)