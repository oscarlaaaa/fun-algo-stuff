struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 2022-05-13
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == target) 
            return cloned;
        
        TreeNode* ans;
        if (original->left)
            ans = getTargetCopy(original->left, cloned->left, target);
        if (!ans && original->right)
            ans = getTargetCopy(original->right, cloned->right, target);
        return ans;
    }
};