struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2023-03-14 (level order traversal)
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        /*
            notes:
            - looks like we can cheese this by doing bfs and grabbing the count of nodes
              at each level of the tree? is that too cheap
                - that'd be o(n) so prob not optimal
                - actually because we're looking for whether the tree is complete, and leaves
                  can be missing from any point at the bottom, it isn't binary search and
            - basically looking through the tree in level-order
            - if we encounter a nullptr at the front, the rest of the nodes in our queue have to
              be nullptrs as well so we clear out all nullptrs
                - if we have any nodes that are still existing after clearing out nullptrs from 
                  the front, that means we don't have a complete binary tree

            analysis:
            - time = O(n) where n=number of nodes
            - space = O(n) where n=number of nodes
        */
        deque<TreeNode*> nodes = {root};
        while (!nodes.empty()) {
            int n = nodes.size();
            for (int i=0; i<n; i++) {
                if (nodes.front() == nullptr) {
                    break;
                } else {
                    nodes.push_back(nodes.front()->left);
                    nodes.push_back(nodes.front()->right);
                }
                nodes.pop_front();
            }
            if (nodes.front() == nullptr) {
                while (nodes.front() == nullptr) {
                    nodes.pop_front();
                }
                break;
            }
        }
        return nodes.empty();
    }
};