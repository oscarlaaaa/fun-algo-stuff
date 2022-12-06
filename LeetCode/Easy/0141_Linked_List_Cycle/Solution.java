
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

//2021-11-16
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) return false;
        Set<ListNode> seen = new HashSet<ListNode>();
        return isThereCycle(head, seen);
    }
    
    private boolean isThereCycle(ListNode head, Set<ListNode> seen) {
        if (head == null) return false;
        if (seen.contains(head)) return true;
        seen.add(head);
        return isThereCycle(head.next, seen);
    }
}