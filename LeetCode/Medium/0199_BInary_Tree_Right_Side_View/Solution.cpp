struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-09-08 (dfs)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        lookFromRightSide(root, 0, view);
        return view;
    }
    
    void lookFromRightSide(TreeNode* root, int depth, vector<int>& view) {
        if (!root)
            return;
        
        if (depth >= view.size())
            view.push_back(root->val);
        
        lookFromRightSide(root->right, depth+1, view);
        lookFromRightSide(root->left, depth+1, view);
    }
};