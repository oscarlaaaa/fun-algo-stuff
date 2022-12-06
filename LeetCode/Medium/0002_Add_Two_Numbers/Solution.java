// 2021-06-01
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return generateNode(l1, l2, 0);
    }
    
    private ListNode generateNode(ListNode l1, ListNode l2, int carry) {
        if (l1 == null && l2 == null && carry == 0) return null;
        if (l1 == null && l2 == null && carry > 0) return new ListNode(carry, null);
        
        if (l1 == null) {
            int sum = l2.val + carry;
            int value = sum % 10;
            carry = sum / 10;
            return new ListNode(value, generateNode(l1, l2.next, carry));
        }
        
        if (l2 == null) {
            int sum = l1.val + carry;
            int value = sum % 10;
            carry = sum / 10;
            return new ListNode(value, generateNode(l1.next, l2, carry));
        }
        
        int sum = l1.val + l2.val + carry;
        int value = sum % 10;
        carry = sum / 10;    
        return new ListNode(value, generateNode(l1.next, l2.next, carry));
        
    }
}