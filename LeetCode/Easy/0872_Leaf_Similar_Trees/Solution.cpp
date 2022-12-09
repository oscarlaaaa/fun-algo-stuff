struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-12-07
class Solution {
public:
    vector<int> findLeafSequence(TreeNode* &root) {
        vector<int> sequence;
        deque<TreeNode*> stack = {root};
        while (!stack.empty()) {
            TreeNode* node = stack.back();
            stack.pop_back();

            if (!node) continue;

            if (!node->left && !node->right) 
                sequence.push_back(node->val);
            
            stack.push_back(node->left);
            stack.push_back(node->right);
        }
        return sequence;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        /*
            input: two tree roots
            output: boolean whether the leaf sequences are similar

            notes:
            - leaf-similar if the sequence of leaves is the same
            - have to traverse to the bottom of each leaf, and record the sequence?
            - can we do without using O(n+m) space?

            approach:
            - go left to right for the first tree and record leaves
            - go right to left for the second tree and pop matches
                - if nothing to pop, then we return false
            - return whether the list is empty at the end
        */
        return findLeafSequence(root1) == findLeafSequence(root2);
    }
};