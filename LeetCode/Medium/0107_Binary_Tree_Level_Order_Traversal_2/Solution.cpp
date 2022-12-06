struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-06-03
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ordering;
        groupTreeLevels(root, 0, ordering);
        reverse(ordering.begin(), ordering.end());
        return ordering;
    }
    
    void groupTreeLevels(TreeNode* root, int level, vector<vector<int>> &ordering) {
        if (!root) return;
        
        while (level >= ordering.size())
            ordering.push_back({});
        
        ordering[level].push_back(root->val);
        groupTreeLevels(root->left, level+1, ordering);
        groupTreeLevels(root->right, level+1, ordering);
    }
};