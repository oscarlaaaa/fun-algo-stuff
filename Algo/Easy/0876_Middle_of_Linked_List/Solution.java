import java.util.*;
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

// 2021-11-13
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode current = head;
        List<ListNode> nodes = new ArrayList<ListNode>();
        
        while (current != null) {
            nodes.add(current);
            current = current.next;
        }
        
        int mid = (nodes.size() / 2);
        return nodes.get(mid);
    }
}