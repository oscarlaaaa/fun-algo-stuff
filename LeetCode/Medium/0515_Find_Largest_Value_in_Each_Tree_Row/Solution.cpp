/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        /*
        notes:
        - process level by level (bfs)
        - each level, queue up next row + grab largest from that row

        analysis:
        - time = O(v) where v=number of nodes
        - space = O(d) where d=diameter of the tree
        */
        vector<TreeNode*> row;
        if (root) 
            row.push_back(root);

        vector<int> largestFromRow;
        while (!row.empty()) {
            int largest = row.front()->val;
            vector<TreeNode*> nextRow;
            for (TreeNode* node : row) {
                largest = max(largest, node->val);
                if (node->left)
                    nextRow.push_back(node->left);
                if (node->right)
                    nextRow.push_back(node->right);
            }
            largestFromRow.push_back(largest);
            row = nextRow;
        }
        return largestFromRow;
    }
};