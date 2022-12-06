from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2022-05-15 (lower memory but more complex)
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if not head:
            return head
        
        lower = lower_head = None
        higher = higher_head = None
        
        cur = head
        while cur:
            if cur.val < x:
                if not lower_head:
                    lower = lower_head = cur
                else:
                    lower.next = cur
                    lower = lower.next
            else:
                if not higher_head:
                    higher = higher_head = cur
                else:
                    higher.next = cur
                    higher = higher.next
            cur = cur.next
        
        output = lower_head if lower_head else higher_head
        if lower and higher_head:
            lower.next = higher_head if higher_head else None
            higher.next = None
            
        return output

## 2022-05-16 (hackerman tactic B) )
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if not head:
            return head
        
        lower, higher = [], []
        while head:
            if head.val < x:
                lower.append(head)
            else:
                higher.append(head)
            head = head.next
        
        full_list = lower + higher
        for i in range(len(full_list)-1):
            full_list[i].next = full_list[i+1]
        full_list[-1].next = None
            
        return full_list[0]
    