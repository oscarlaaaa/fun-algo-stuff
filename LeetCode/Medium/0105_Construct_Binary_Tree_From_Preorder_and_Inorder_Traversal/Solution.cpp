struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-05-23 (recursive approach)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        
        TreeNode* root = new TreeNode;
        root->val = preorder[0];
        
        auto breakpoint = find(inorder.begin(), inorder.end(), preorder[0]);
        vector<int> leftInorder(inorder.begin(), breakpoint);
        vector<int> rightInorder(breakpoint+1, inorder.end());
        
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+1+leftInorder.size());
        vector<int> rightPreorder(preorder.end() - rightInorder.size(), preorder.end());
        
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        
        return root;
    }
};