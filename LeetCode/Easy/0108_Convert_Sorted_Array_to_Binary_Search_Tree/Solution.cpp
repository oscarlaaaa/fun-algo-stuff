struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-09-07 (dfs)
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* bst = buildBST(nums, 0, nums.size());
        return bst;
    }
    
    TreeNode* buildBST(vector<int>& nums, int start, int end) {
        if (start >= end) 
            return nullptr;
        
        int mid = start + (end-start)/2;
        TreeNode* node = new TreeNode(nums[mid], buildBST(nums, start, mid), buildBST(nums, mid+1, end));
        return node;
    }
};