struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 2022-10-14 (fast-slow pointers)
//
// 
// approach:
//  - new node pointing to head
//  - keep track of prev, cur, and a scout
//  - scout moves at 2x the rate of cur, and when it is null then
//    cur would be at the halfway mark and we can use prev to delete the 
//    current node
//
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *newHead = new ListNode(-1, head);
        ListNode *prev = newHead, *cur = head, *scout = head;
        
        while (scout != nullptr && scout->next != nullptr) {
            prev = cur;
            cur = cur->next;
            scout = scout->next->next;
        }
        prev->next = cur->next;
        return newHead->next;
    }
};