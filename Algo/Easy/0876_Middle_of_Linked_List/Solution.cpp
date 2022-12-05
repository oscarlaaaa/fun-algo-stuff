struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 2022-12-04 (fast-slow)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        /*
            input: a linked list
            output: the middle node of the list (2nd middle if even number)

            approach:
            - fast and slow pointer starting at a ghost node
            - fast pointer moves forward 2 every time slow pointer moves 1
            - stop iterating when fast pointer == null
            - return slow pointer
        */
        ListNode *ghost = new ListNode(-1, head);
        ListNode *fast = ghost, *slow = ghost;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
                fast = fast->next;
        }
        return slow;

    }
};