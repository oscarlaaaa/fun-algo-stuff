from typing import *
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

## 2022-08-22 (Follow-up - O(n) time, O(1) space)
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        ## count length of the LL
        length = 0
        cur = head
        while cur:
            length += 1
            cur = cur.next
        
        ## reverse LL before the half-way mark
        left = None
        right = head
        for _ in range(length//2):
            next_node = right.next
            right.next = left
            left = right
            right = next_node
        
        ## if length is odd, we have a single node in the center we can ignore
        if length % 2 == 1:
            right = right.next
        
        ## ensure that they match all the way thru
        while right and left and right.val == left.val:
            right, left = right.next, left.next
            
        return right == left == None
        