struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2023-04-18 (BFS)
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        /*
        notes:
        - can probably do bottom-up recursion?
            - OR just do BFS downwards
        - queue with {node, left-zag, right-zag}

        complexity:
        - time = O(v) where v=number of nodes
        - space = O(w) where w=max width of our b-tree
        */
        int longest = 0;
        deque<pair<TreeNode*, pair<int, int>>> queue = {{root, {0, 0}}};
        while (!queue.empty()) {
            auto [node, zigzags] = queue.front();
            auto [zig, zag] = zigzags;
            queue.pop_front();

            longest = max(longest, max(zig, zag));
            if (node->left)
                queue.push_back({node->left, {zag+1, 0}});
            if (node->right)
                queue.push_back({node->right, {0, zig+1}});
        }
        return longest;
    }
};