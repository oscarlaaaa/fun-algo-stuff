struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-09-07 (dfs + backtracking)
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curPath;
        vector<vector<int>> foundPaths;
        
        findAllPaths(root, targetSum, curPath, foundPaths);
        return foundPaths;
    }
    
    void findAllPaths(TreeNode* root, int remaining, vector<int>& curPath, vector<vector<int>>& foundPaths) {
        if (root == nullptr) return;
        
        curPath.push_back(root->val);
        remaining -= root->val;
        
        // check if it's a leaf as well
        if (remaining == 0 && root->left == nullptr && root->right == nullptr) {
            vector<int> addPath = curPath;
            foundPaths.push_back(addPath);
        }
        
        findAllPaths(root->left, remaining, curPath, foundPaths);
        findAllPaths(root->right, remaining, curPath, foundPaths);
        curPath.pop_back();
    }
};