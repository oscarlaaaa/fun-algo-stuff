from typing import *

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

## 2022-05-11
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False
        
        turtle, hare = head, head.next
        
        while turtle and hare:
            if hare == turtle or hare.next == turtle:
                return True
            
            turtle = turtle.next
            hare = hare.next.next if hare.next else None
        
        return False

## 2022-11-09 (slow-fast pointer)
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        """
        input: head of a linked list
        output: bool whether the list has a cycle

        constraints:
        - may have no loop existing

        approach:
        - one fast, one slow pointer
        - run loop until fast pointer or fast pointer's next is None (no cycle)
        - check the fast pointer, and fast poniter's next if they match the slow pointer
        """

        ghost = ListNode(-1, head)
        slow, fast = ghost, head
        while fast and fast.next:
            if fast == slow or fast.next == slow:
                return True
            slow = slow.next
            fast = fast.next.next
        return False
