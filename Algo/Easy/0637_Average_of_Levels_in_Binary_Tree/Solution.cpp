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
    #define ll long long
    vector<double> averageOfLevels(TreeNode* root) {
        vector<ll> counts, sums;
        
        sumAndCountLevels(root, counts, sums, 0);
        
        vector<double> means;
        for (int i=0; i<counts.size(); i++) {
            means.push_back((double) sums[i]/counts[i]);
        }
        return means;
    }
    
    void sumAndCountLevels(TreeNode* root, vector<ll>& counts, vector<ll>& sums, int level) {
        if (root == nullptr) return;
        
        if (level >= counts.size()) {
            counts.push_back(0);
            sums.push_back(0);
        }
        
        counts[level]++;
        sums[level] += root->val;
        
        sumAndCountLevels(root->left, counts, sums, level+1);
        sumAndCountLevels(root->right, counts, sums, level+1);
    }
};