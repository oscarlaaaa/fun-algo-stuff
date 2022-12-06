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
    private int solve(TreeNode root, int count){
        if (root == null) {
            return count;
        } else {
            count++;
            int left = solve(root.left, count);
            int right = solve(root.right, count);
            if (left > right){
                return left;
            } else {
                return right;
            }
        } 
    }
    
    public int maxDepth(TreeNode root) {
        int count = 0;
        return solve(root, count);
    }
}