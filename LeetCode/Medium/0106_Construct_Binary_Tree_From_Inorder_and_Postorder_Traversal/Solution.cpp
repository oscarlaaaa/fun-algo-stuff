struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2023-03-15 (recursion baybee)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*
            notes:
            - last val of postorder = the root of the current position
            - split preorder based on location of root
            - split postorder based on vals within preorder
            - recurse down

            analysis:
            - time = O(nlogn) where n=num of nodes
            - space = O(n) where n=num of nodes
        */
        if (inorder.size() == 0)
            return nullptr;

        if (inorder.size() == 1)
            return new TreeNode(inorder.back());
        
        int index = find(inorder.begin(), inorder.end(), postorder.back()) - inorder.begin();

        vector<int> leftInorder = vector<int>(inorder.begin(), inorder.begin()+index), 
                    rightInorder = vector<int>(inorder.begin()+index+1, inorder.end());
        vector<int> leftPostorder = vector<int>(postorder.begin(), postorder.begin()+index), 
                    rightPostorder = vector<int>(postorder.begin()+index, postorder.end()-1);
            
        TreeNode* root = new TreeNode(postorder.back());
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};