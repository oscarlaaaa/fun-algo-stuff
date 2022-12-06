from typing import *
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2022-11-03
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = num_sum = ListNode(-1)
        carry = 0
        while l1 and l2:
            next_sum = l1.val + l2.val + carry
            carry, val= next_sum//10, next_sum%10
            num_sum.next = ListNode(val)
            l1, l2, num_sum = l1.next, l2.next, num_sum.next
        
        remain = l1 if l1 else l2
        while remain:
            next_sum = remain.val + carry
            carry, val= next_sum//10, next_sum%10
            num_sum.next = ListNode(val)
            remain, num_sum = remain.next, num_sum.next
            
        if carry:
            num_sum.next = ListNode(1)

        return head.next
