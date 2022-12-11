struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-12-11 (DFS pre-order traversal)
class Solution {
public:
    int longestPath = INT_MIN;
    int postorderPathSum(TreeNode* node) {
        if (!node) return 0;

        int leftSum = postorderPathSum(node->left);
        int rightSum = postorderPathSum(node->right);

        int longest = node->val;
        if (leftSum > 0) longest += leftSum;
        if (rightSum > 0) longest += rightSum;
            
        longestPath = max(longestPath, node->val);
        longestPath = max(longestPath, longest);

        return max(node->val, max(leftSum + node->val, rightSum + node->val));
    }
    int maxPathSum(TreeNode* root) {
        /*
            input: a binary tree
            output: maximum path sum within the tree

            notes:
            - a path can only appear in the sequence at most once
            - path doesn't need to include the root
            - maybe recursive function where we track a global maximum and return
              the longest single path + current node with each call?
              - postorder traversal to cover children first
              - the next call from the stack will take the result and see if it can generate a
                better global max with/without it, and return the greatest child path + itself
                or just itself if it's greater than itself+childpath
            - return global max
        */

        postorderPathSum(root);
        return longestPath;      
    }
};
