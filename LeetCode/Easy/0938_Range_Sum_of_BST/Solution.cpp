struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-12-06
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        /*
            input: a bst and a low/high range
            output: sum of nodes within the inclusive low/high range

            approach:
            - add up nodes recursively, and return upwards
            - sum starts at 0 and represents sum of node + children within range
            - if current node is within bounds, add to sum
            - add recursive call of left/right children to sum and return
        */
        if (!root) return 0;

        int sum = 0;
        if (low <= root->val && root->val <= high)
            sum += root->val;
        if (root->val < high) 
            sum += rangeSumBST(root->right, low, high);
        if (root->val > low)
            sum += rangeSumBST(root->left, low, high);
        return sum;
    }
};