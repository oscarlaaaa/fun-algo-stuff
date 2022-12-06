struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 2022-06-08
/**
 * The approach to this is that you start from both ends, and iterate down.
 * If one reaches the end before the other, then you'd start that pointer again
 * at the other head. The idea is that if you run each pointer along one path,
 * then the other, their rates will sync up and they should hit an intersection
 * at the same time IF there is an intersection. If they both reach either nullptr
 * or the same node at the same time, we can just return one of the pointers.
 * 
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        
        if (a == b) return a;
        
        while (a && b && a != b) {
            
            a = a->next;
            b = b->next;
            
            if (a == b) return a;
            
            if (a == nullptr) a = headB;
            if (b == nullptr) b = headA;
        }
        return a;
    }
};