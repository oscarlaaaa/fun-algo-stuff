class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// 2021-03-17
class Solution {
    public void flipLevel(TreeNode root) {
        TreeNode hold = root.left;
        root.left = root.right;
        root.right = hold;
    }
    
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return root;
        } else {
            flipLevel(root);
            invertTree(root.left);
            invertTree(root.right);
        }
        return root;
    }
}