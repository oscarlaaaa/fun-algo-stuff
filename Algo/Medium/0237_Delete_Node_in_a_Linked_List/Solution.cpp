struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 2022-10-13
//
// We pass the values up to replace the 'deleted' node, and delete the last node
// to adjust the length of the list.
//
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* cur = node;
        while (cur->next) {
            cur->val = cur->next->val;
            if (!cur->next->next) {
                cur->next = nullptr;
                return;
            }
            cur = cur->next;
        }       
    }
};