class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

//2021-05-18
class Solution {
    private void merge(ListNode list1, ListNode list2) {
        if (list1 == null || list2 == null) return;
        ListNode nextnode = list2;
        if (list1.val >= list2.val) {
            while (list2.next != null && list2.next.val <= list1.val)
                list2 = list2.next;
            nextnode = list2.next;
            list2.next = list1;
        }
        merge(nextnode, list1);
    }
    
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        merge(l1, l2);
        if (l1 == null && l2 == null) return null;
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        if (l1.val >= l2.val) return l2;
        return l1;
    }
}

//2021-11-16
class Solution2 {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) return null;
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        
        if (l1.val < l2.val) {
            ListNode next = l1.next;
            l1.next = mergeTwoLists(next, l2);
            return l1;
        } else {
            ListNode next = l2.next;
            l2.next = mergeTwoLists(l1, next);
            return l2;
        }
    }
}