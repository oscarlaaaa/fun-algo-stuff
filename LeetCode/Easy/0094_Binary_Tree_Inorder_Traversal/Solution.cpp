struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-09-08 (iterative)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        
        vector<int> output;
        unordered_set<TreeNode*> seen;
        deque<TreeNode*> stack;
        stack.push_back(root);
        
        while (stack.size() > 0) {
            TreeNode* cur = stack.back();
            if (seen.count(cur)) {
                output.push_back(cur->val);
                stack.pop_back();
                if (cur->right)
                    stack.push_back(cur->right);
            } else {
                seen.insert(cur);
                if (cur->left)
                    stack.push_back(cur->left);
            }
        }
        return output;
    }
};