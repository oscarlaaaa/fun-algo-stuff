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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> path = new ArrayList<Integer>();
        traversePreorder(root, path);
        return path;
    }
    
    private void traversePreorder(TreeNode root, List<Integer> path) {
        if (root == null) return;
        path.add(root.val);
        traversePreorder(root.left, path);
        traversePreorder(root.right, path);
    }
}

// 2021-11-18 (Iterative)
class Solution2 {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> path = new ArrayList<Integer>();
        Deque<TreeNode> stack = new ArrayDeque<TreeNode>();
        
        if (root != null) {
            stack.addFirst(root);
        }
        
        while (!stack.isEmpty()) {
            TreeNode current = stack.pop();
            path.add(current.val);
            if (current.right != null) {
                stack.addFirst(current.right);
            }
            if (current.left != null) {
                stack.addFirst(current.left);
            }
        }
        
        return path;
    }
}