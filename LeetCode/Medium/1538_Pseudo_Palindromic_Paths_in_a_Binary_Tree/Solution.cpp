struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-09-16 (DFS)
class Solution {
public:
    vector<int> counts = vector<int>(10, 0);
    int pseudoPalindromicPaths(TreeNode* root) {
        if (!root) 
            return 0;
        
        this->counts[root->val]++;
        
        int total = 0;
        if (!root->left && !root->right) {  // is leaf node
            int numOfOdds = 0;
            for (const auto& count : this->counts) {
                if (count&1) numOfOdds++;
            }
            // pseudo-palindromes can only have at most 1 odd frequency
            total = numOfOdds <= 1 ? 1 : 0;
        } else {
            total = pseudoPalindromicPaths(root->left) + pseudoPalindromicPaths(root->right);
        }
        
        this->counts[root->val]--;
        return total;
    }
};