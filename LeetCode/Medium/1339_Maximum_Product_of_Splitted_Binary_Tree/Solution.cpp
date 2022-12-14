struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-12-09 (DFS-memoization)
class Solution {
public:
    int sumOfTree(TreeNode* node, unordered_map<TreeNode*, int>& sums) {
        if (!node) 
            return 0;
        if (sums.count(node)) 
            return sums[node];
            
        sums[node] = node->val + sumOfTree(node->left, sums) + sumOfTree(node->right, sums);
        return sums[node];
    }
    int maxProduct(TreeNode* root) {
        /*
            input: binary tree (not bst)
            output: the maximum product of the sums of the two subtrees

            notes:
            - edges are always between a child and its parent
            - the greatest product would have both halves as even as possible
                - difference between two subtrees = smallest
            
            approach:
            - DFS approach          
                - sum up the tree, then find the subtree closest to half of the sum
                - could probably approach this recursively or iteratively?
            - perform using a stack, where it holds pairs of a node and a pair of booleans
                - booleans represent whether we've added the left/right children yet
            - just do recursively to save time
        */
        unordered_map<TreeNode*, int> sums;
        int total = sumOfTree(root, sums);
        long long curBest = 0;
        for (auto itr=sums.begin(); itr != sums.end(); itr++) {
            auto [_, sum] = *itr;
            long long product = 1LL*sum*(total-sum);
            if (product > curBest)
                curBest = product;
        }
        return curBest % (int)(1e9 + 7);
    }
};