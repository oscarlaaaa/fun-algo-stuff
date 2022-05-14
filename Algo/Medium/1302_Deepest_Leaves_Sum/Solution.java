public class TreeNode {
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

// 2022-05-13
class Solution {
    public int deepestLeavesSum(TreeNode root) {
        int[] deepest = new int[2];
        addLeaves(root, 0, deepest);
        return deepest[1];
        
    }
    
    private void addLeaves(TreeNode root, int depth, int[] deepest) {
        if (root == null) return;
        
        if (depth > deepest[0]) {
            deepest[0] = depth;
            deepest[1] = 0;
        }
        
        if (depth == deepest[0]) 
            deepest[1] += root.val;
        
        addLeaves(root.left, depth+1, deepest);
        addLeaves(root.right, depth+1, deepest);
    }
}