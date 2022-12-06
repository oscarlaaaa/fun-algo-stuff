struct ListNode {
    int val;
    struct ListNode *next;
};

// 2021-12-11
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    if (node == NULL) {
        exit(1);
    }
    
    node->val = val;
    node->next = NULL;
    return node;
}


struct ListNode* addTwoNumbersCarry(struct ListNode* l1, struct ListNode* l2, int carry){
    if (l1 == NULL && l2 == NULL) {
        if (carry == 0) {
            return NULL;
        } else {
            return createNode(carry);
        }
    }
    
    if (l1 == NULL || l2 == NULL) {
        struct ListNode* node = l1 == NULL ? l2 : l1;
        
        int total = node->val + carry;
        int nodeval = total % 10;
        carry = total / 10;
        
        struct ListNode* newNode = createNode(nodeval);
        newNode->next = addTwoNumbersCarry((l1 == NULL ? l1 : l1->next), (l2 == NULL ? l2 : l2->next), carry);
        return newNode;
    }
    
    int total = l1->val + l2->val + carry;
    
    int nodeval = total % 10;
    carry = total / 10;

    struct ListNode* newNode = createNode(nodeval);
    newNode->next = addTwoNumbersCarry(l1->next, l2->next, carry);
    return newNode;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    return addTwoNumbersCarry(l1, l2, 0);
}