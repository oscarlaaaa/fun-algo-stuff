struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;
        
        ListNode *lower, *lowerHead = nullptr;
        ListNode *greater, *greaterHead = nullptr;
        
        ListNode *current = head;
        while (current) {
            if (current->val < x) {
                if (!lowerHead) {
                    lower = lowerHead = current;
                } else {
                    lower->next = current;
                    lower = lower->next;
                }
            } else {
                if (!greaterHead) {
                    greater = greaterHead = current;
                } else {
                    greater->next = current;
                    greater = greater->next;
                }
            }
            current = current->next;
        }
        
        ListNode *output;
        if (lowerHead) {
            output = lowerHead;
            lower->next = greaterHead;
        } else {
            output = greaterHead;
        }
        
        if (greaterHead) 
            greater->next = nullptr;
        
        return output;
    }
};