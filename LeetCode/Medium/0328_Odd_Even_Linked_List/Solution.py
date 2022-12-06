from typing import *
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2021-12-04
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
    
        
        odds = None
        odds_head = None
        
        evens = None
        evens_head = None
        
        count = 1
        while head:
            if count % 2 == 1:
                if not odds:
                    odds = head
                    odds_head = head
                else:
                    odds.next = head
                    odds = head
            else:
                if not evens:
                    evens = head
                    evens_head = head
                else:
                    evens.next = head
                    evens = head
            head = head.next
            count += 1
        
        
        odds.next = evens_head
        evens.next = None
        return odds_head