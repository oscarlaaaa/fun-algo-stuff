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

// 2021-07-03 (Recursive)
class Solution {
    // Output variable
    private int longest;
    
    public int diameterOfBinaryTree(TreeNode root) {
        findLength(root);
        return longest;
    }
    
    private int findLength(TreeNode root) {
        
        // Base case
        if (root == null) return 0;
        
        // Check the lengths of both sides
        int leftLength = findLength(root.left);
        int rightLength = findLength(root.right);
        
        // Sets the new longest if the node's longest is greater
        longest = Math.max(longest, leftLength + rightLength);
        
        // Returns the current node plus the greatest length
        return 1 + Math.max(leftLength, rightLength);
    }
}