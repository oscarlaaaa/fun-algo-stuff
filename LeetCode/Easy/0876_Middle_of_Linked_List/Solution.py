from typing import *
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2021-12-27 (fast-slow)
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        count = 1
        fast = head
        slow = head
        
        while fast is not None:
            if count % 2 == 0:
                slow = slow.next
            fast = fast.next
            count += 1
        
        return slow