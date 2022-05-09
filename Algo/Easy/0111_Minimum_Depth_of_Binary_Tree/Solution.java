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

// 2021-08-08
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        Deque<TreeNode> queue = new ArrayDeque<TreeNode>();
        queue.add(root);
        return findMinDepth(queue, 1);
    }
    
    private int findMinDepth(Deque<TreeNode> queue, int depth) {
        Deque<TreeNode> nextQueue = new ArrayDeque<TreeNode>();
        while (!queue.isEmpty()) {
            TreeNode check = queue.getFirst();
            queue.removeFirst();
            if (check.left == null && check.right == null) return depth;
            if (check.left != null) nextQueue.add(check.left);
            if (check.right != null) nextQueue.add(check.right);
        }
        return findMinDepth(nextQueue, depth + 1);
    }
}