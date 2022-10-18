class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 2021-03-21 (recursive)
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head != null) {
            return solve (head, null);
        } else {
            return head;
        }
    }
    
    private ListNode solve(ListNode head, ListNode prev) {
        ListNode nextNode = head.next;
        head.next = prev;
        if (nextNode != null) {
            prev = head;
            return solve(nextNode, prev);
        } else {
            return head;
        }
    }
}

// 2021-11-16 (recursive)
class Solution2 {
    public ListNode reverseList(ListNode head) {
        return reverseNodes(head, null);
    }
    
    private ListNode reverseNodes(ListNode current, ListNode previous) {
        if (current == null) return previous;
        ListNode next = current.next;
        current.next = previous;
        return reverseNodes(next, current);
    }
}