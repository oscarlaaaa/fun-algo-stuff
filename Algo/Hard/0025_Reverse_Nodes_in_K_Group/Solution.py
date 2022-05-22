from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2022-02-05 
class Solution:
    HEAD_INDEX = 0
    TAIL_INDEX = 1
    
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k == 1:
            return head
        
        current = head
        count = 1
        total_head, group_head, previous_tail = (None, None, None)
        
        while current:
            if count == 1:
                group_head = current
            
            if count == k:
                count = 0
                next_node = current.next
                reversed_section = Solution.reverseGroup(group_head, current)
                
                if total_head is None:
                    total_head = reversed_section[Solution.HEAD_INDEX]
                
                if previous_tail:
                    previous_tail.next = reversed_section[Solution.HEAD_INDEX]
                    
                previous_tail = reversed_section[Solution.TAIL_INDEX]
                current = next_node
                group_head = None
            else:
                current = current.next
            count += 1
        
        if group_head:
            previous_tail.next = group_head
        
        return total_head
                
                
    def reverseGroup(head, tail):
        if head is None:
            return head
        
        previous = None
        current = head
        while current and previous is not tail:
            temp = current.next
            current.next = previous
            previous = current
            current = temp
            
        return (tail, head)
