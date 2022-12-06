// 2022-05-13
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    void addLeaves(TreeNode* root, int depth, vector<int>& sums) {
        if (sums.size() <= depth) 
            sums.push_back(0);
        
        sums[depth] += root -> val;
        
        if (root->left) addLeaves(root->left, depth+1, sums);
        if (root->right) addLeaves(root->right, depth+1, sums);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        vector<int> sums;
        addLeaves(root, 0, sums);
        int depth = sums.size()-1;
        return sums[depth];
    }
};