public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 2021-11-13
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode prev = head;
        ListNode current = head;
        ListNode NAhead = head;
        
        for (int i = 0; i < n; i++) {
            NAhead = NAhead.next;
        }
        
        while (NAhead != null) {
            prev = current;
            current = current.next;
            NAhead = NAhead.next;
        }
        
        if (prev == current) {
            return current.next;
        } else {
            prev.next = current.next;
            return head;
        }       
    }
    
}