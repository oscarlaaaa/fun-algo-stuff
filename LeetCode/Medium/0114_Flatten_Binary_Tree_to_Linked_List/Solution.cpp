struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-11-15 (recursive, O(1) extra space)
class Solution {
public:
    void flatten(TreeNode* root) {
        preorderTraversal(root);
    }

    TreeNode* preorderTraversal(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* left = preorderTraversal(root->left);
        TreeNode* right = preorderTraversal(root->right);
        root->right = attachLists(left, right);
        root->left = nullptr;
        return root;
    }

    TreeNode* attachLists(TreeNode* l, TreeNode* r) {
        if (!l) return r;

        TreeNode* cur = l;
        while (cur && cur->right) 
            cur = cur->right;
        cur->right = r;
        return l;
    }
};