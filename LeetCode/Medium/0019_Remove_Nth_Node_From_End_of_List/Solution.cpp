struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 2022-12-25 (fast-slow pointers)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            input: a linked list head. and an int n
            output: the linked list head with the nth node removed

            notes:
            - immediate thoughts would be a fast and slow pointer
            - fast pointer would be n nodes ahead of slow, and then iterate together
            - remove whatever slow is pointing to once fast is nullptr

            approach:
            - use ghost node to track the head (in case we remove head)
            - start both fast and slow pointers at the ghost node
            - iterate fast pointer n times
            - iterate both fast and slow pointers together until fast's next is null
            - remove whatever slow's next is pointing to and return ghost pointer's next
        */
        ListNode *ghost = new ListNode(-1, head);
        ListNode *fast = ghost, *slow = ghost;
        for (int i=0; i<n; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return ghost->next;
    }
};