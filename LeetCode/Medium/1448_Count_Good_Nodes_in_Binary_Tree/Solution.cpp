struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-09-01
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, -100000);
    }
    
    int countGoodNodes(TreeNode* root, int largest) {
        if (root == nullptr) return 0;
        
        int leftSide = countGoodNodes(root->left, max(largest, root->val));
        int rightSide = countGoodNodes(root->right, max(largest, root->val));
        
        return (root->val >= largest ? 1 : 0) + leftSide + rightSide;
    }
};