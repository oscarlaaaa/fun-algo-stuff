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