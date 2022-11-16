struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2022-11-15 (binary search)
class Solution {
public:
    /*
    input: binary tree root node
    output: number of nodes in the binary tree

    notes:
    - must be less than O(n)
    - every level except (possibly) the last is completely filled in

    approach:
    - binary search for O(logn) runtime to find the gap
    - check the middle node (go left, then all the way right)
        - if middle node exists, means that empty gap is to the right so we need to
          call recursive function on the right node
        - else, empty gap is to the left so call recursive function on the left node
    */
    int count = 0;
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        // find lowest depth node
        TreeNode *l = root->left;
        int depth = 0;
        while (l != nullptr) {
            depth++;
            l = l->left;
        }
        for (int i=0; i<depth; i++) {
            count += (int) pow(2, i);
        }
        
        greatestPosition(root, depth);
        return count;
    }

    void greatestPosition(TreeNode* node, int height) {
        if (!node || (height==0 && count++)) return;

        int depth = countHeight(node->left);
        if (depth == height) {
            count += (int) pow(2, height-1);
            greatestPosition(node->right, height-1);
        } else {
            greatestPosition(node->left, height-1);
        }  
    }      

    int countHeight(TreeNode* node) {
        if (!node) return 0;
        return 1 + countHeight(node->right);
    }
};