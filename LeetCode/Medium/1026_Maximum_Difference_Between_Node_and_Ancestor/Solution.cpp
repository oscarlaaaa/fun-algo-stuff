struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-12-08 (iterative DFS)
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        /*
            input: root node of a binary tree
            output: the maximum value where v=|a.val - b.val| and a is an ancestor of b

            notes:
            - at least 2 nodes in the tree
            - node values are not unique
            - want the greatest difference between a node and its child
            - whether node or child are smaller doesn't matter since we take absolute
            - 2 useful values as we traverse:
                - lowest value the subtree has
                - higherst value the subtree has
            
            approach:
            - DFS using an iterative stack
            - stack holds the node, and the current min/max
            - check for maximum value from max-cur val, and min-cur val
            - check if it replaces the current min/max 
            - push the new children with the new min/max in
        */
        int maximum = 0;
        deque<pair<TreeNode*, pair<int, int>>> stack = {{root, {root->val, root->val}}};
        while (!stack.empty()) {
            auto [node, bounds] = stack.back();
            auto [curMin, curMax] = bounds;
            stack.pop_back();

            maximum = max(maximum, max(abs(curMin - node->val), abs(curMax - node->val)));
            
            pair<int, int> nextBounds = {min(curMin, node->val), max(curMax, node->val)};
            if (node->left)
                stack.push_back({node->left, nextBounds});
            if (node->right)
                stack.push_back({node->right, nextBounds});
        }
        return maximum;
    }
};