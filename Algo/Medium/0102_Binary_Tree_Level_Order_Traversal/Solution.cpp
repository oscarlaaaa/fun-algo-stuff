using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-05-20
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> records;
        addToLevel(root, 0, records);
        return records;
    }
    
    void addToLevel(TreeNode* root, int level, vector<vector<int>>& records) {
        if (!root) return;
        if (level >= records.size()) {
            vector<int> newLevel;
            records.push_back(newLevel);
        }
        
        records[level].push_back(root->val);
        addToLevel(root->left, level+1, records);
        addToLevel(root->right, level+1, records);
    }
};