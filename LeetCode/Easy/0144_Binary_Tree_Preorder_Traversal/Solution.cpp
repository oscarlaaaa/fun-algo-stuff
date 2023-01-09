// 2022-01-08 (iterative DFS)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        /*
            input: a binary tree
            output: the pre-order traversal of the tree

            notes:
            - preorder is the node, then children

            approach:
            - use a stack to process left, then right subtrees
                - add right child, then left so that left gets processed first
            - store all traversed nodes into a vector and return
        */
        if (!root)
            return {};
            
        vector<int> output;
        deque<TreeNode*> stack = {root};
        while (!stack.empty()) {
            auto node = stack.back();
            stack.pop_back();
            output.push_back(node->val);

            if (node->right)
                stack.push_back(node->right);
            if (node->left)
                stack.push_back(node->left);
        }
        return output;
    }
};