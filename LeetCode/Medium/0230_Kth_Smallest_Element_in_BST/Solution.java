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

// 2021-06-24
class Solution {
    private static int output; // output value
    private static int count; // count of values starting from lowest
    private static int index; // k value to keep track of
    
    private void recurse(TreeNode root) {
        if (root.left != null) recurse(root.left); // recurse if left is available
        
        if (++count == index) output = root.val; // increment count; set output as root value if count = k
        
        if (root.right != null) recurse(root.right); // recurse if right is available
    }
    
    public int kthSmallest(TreeNode root, int k) {
        
        // initialize static variables
        output = 0;
        index = k;
        count = 0;
        
        // recursion
        recurse(root);
        
        return output;
    }
}