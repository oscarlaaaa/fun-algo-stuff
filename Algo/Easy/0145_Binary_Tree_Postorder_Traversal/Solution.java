import java.util.*;

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

// 2021-11-18 (Recursive)
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> path = new ArrayList<Integer>();
        traverse(root, path);
        return path;
    }
    private void traverse(TreeNode root, List<Integer> path) {
        if (root == null) return;
        traverse(root.left, path);
        traverse(root.right, path);
        path.add(root.val);
    }
}