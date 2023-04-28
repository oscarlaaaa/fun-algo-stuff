struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2023-04-28 (bfs)
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        /*
        notes:
        - generating root to leaf paths in any order
        - probably breadth first search? makes sense to me
            - process all paths and queue up current node + current path
        */
        vector<string> output;
        deque<pair<TreeNode*, string>> queue = {{root, ""}};

        while (!queue.empty()) {
            auto [node, path] = queue.front();
            queue.pop_front();

            path += to_string(node->val);
            if (!node->left && !node->right) {
                output.push_back(path);
                continue;
            }

            path += "->";
            if (node->left)
                queue.push_back({node->left, path});
            if (node->right)
                queue.push_back({node->right, path});
        }
        return output;
    }
};