import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

// 2021-11-04
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> seenA = new HashSet<ListNode>();
        Set<ListNode> seenB = new HashSet<ListNode>();
        
        ListNode currA = headA;
        ListNode currB = headB;
        
        while (currA != null || currB != null) {
            seenA.add(currA);
            seenB.add(currB);
            
            if (seenA.contains(currB)) return currB;
            if (seenB.contains(currA)) return currA;
            
            if (currA != null) currA = currA.next;
            if (currB != null) currB = currB.next;
        }
        
        return null;
    }
}