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

// 2021-06-09
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        // Create output list
        List<Integer> output = new ArrayList<Integer>();
        
        // Run the recursive function
        addLeftFirst(root, output);
        
        return output;
    }
    
    private void addLeftFirst(TreeNode root, List<Integer> list) {
        
        // Base case
        if (root == null) return;
        
        // Run recursion down left node first
        addLeftFirst(root.left, list);
        
        // Add root value to list
        list.add(root.val);
        
        // Run recursion down right node last
        addLeftFirst(root.right, list);
    }
}

// 2021-11-18 - Recursive
class Solution2 {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> path = new ArrayList<Integer>();
        traverse(root, path);
        return path;
    }
    
    private void traverse(TreeNode root, List<Integer> path) {
        if (root == null) return;
        traverse(root.left, path);
        path.add(root.val);
        traverse(root.right, path);
    }
}

// 2021-11-18 - Iterative
class Solution3 {
    public List<Integer> inorderTraversal(TreeNode root) {
        
        List<Integer> path = new ArrayList<Integer>();
        Set<TreeNode> seen = new HashSet<TreeNode>();
        Deque<TreeNode> stack = new ArrayDeque<TreeNode>();
        
        if (root != null) {
            stack.addFirst(root);
        }
        
        while (!stack.isEmpty()) {
            TreeNode current = stack.pop();
            if (current.left == null || seen.contains(current.left)) {
                seen.add(current);
                path.add(current.val);
                if (current.right != null) {
                    stack.addFirst(current.right);
                }
                
            } else {
                stack.addFirst(current);
                stack.addFirst(current.left);
            }
        }
        
        return path;
    }
}