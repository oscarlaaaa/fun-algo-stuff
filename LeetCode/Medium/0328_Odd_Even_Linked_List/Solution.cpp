struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 2022-12-05
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(), *even = new ListNode();
        ListNode* oddHead = odd, *evenHead = even;

        int i = 1;
        while (head) {
            if (i&1 == 1) {
                odd->next = head;
                odd = odd->next;
            } else {
                even->next = head;
                even = even->next;
            }
            i++;
            head = head->next;
        }

        even->next = nullptr;
        odd->next = evenHead->next;
        return oddHead->next;
    }
};