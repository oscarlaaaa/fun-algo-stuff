struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-05-21 (kinda hacky but w.e B))
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> order;
        zigzag(root, 0, order);
        for (int i = 1; i < order.size(); i += 2) 
            reverse(order[i].begin(), order[i].end()); // kinda hacky B)
        return order;
    }
    
    void zigzag(TreeNode* root, int level, vector<vector<int>>& order) {
        if (!root) return;
        
        if (order.size() <= level)
            order.push_back({});
        
        order[level].push_back(root->val);
        zigzag(root->left, level+1, order);
        zigzag(root->right, level+1, order);
    }
};