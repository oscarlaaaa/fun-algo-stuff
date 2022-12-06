struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-09-05 (dfs)
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        pruneIfDoesntContainOne(root);
        
        // empty tree with the root value being 0
        if (root->val == 0 && root->left == nullptr && root->right == nullptr)
            return nullptr;
        
        return root;
    }
    
    bool pruneIfDoesntContainOne(TreeNode* root) {
        if (!root) return false;
        
        bool leftContainsOne = pruneIfDoesntContainOne(root->left);
        bool rightContainsOne = pruneIfDoesntContainOne(root->right);
        
        if (!leftContainsOne) {
            delete root->left;
            root->left = nullptr;
        }
        if (!rightContainsOne) {
            delete root->right;
            root->right = nullptr;
        }
        
        if (root->val == 1 || leftContainsOne || rightContainsOne)
            return true;
        
        return false;
    }
};