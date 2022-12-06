from typing import *
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2022-02-18 (hacky way heh)
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if head is None:
            return head
        
        stackueue = []
        current_node = head
        while current_node:
            stackueue.append(current_node)
            current_node = current_node.next
        
        output = stackueue.pop(0)
        first = False
        while len(stackueue) > 0:
            output.next = stackueue.pop(0) if first else stackueue.pop() 
            output = output.next
            first = not first
        
        output.next = None
        return head

## 2022-11-08 (fast-slow strat)
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next:
            return head

        ghostie = ListNode(-1, head)

        # find halfway point
        slow, fast = ghostie, ghostie
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        next_half = slow.next
        slow.next = None # cut off first half from second

        # reverse second half of the list
        prev, cur = None, next_half
        while cur and cur.next:
            next_node = cur.next
            cur.next = prev
            prev, cur = cur, next_node
        cur.next = prev

        # merge the two halves together
        start = prev = ListNode(-1, head)
        while head and cur:
            next_head, next_cur = head.next, cur.next
            prev.next = head
            head.next = cur
            prev, head, cur = cur, next_head, next_cur
        prev.next = head if head else cur
        
        return start.next
