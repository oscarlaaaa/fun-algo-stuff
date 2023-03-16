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

// 2021-11-20
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length == 0 || postorder.length == 0) return null;
        
        int centerElement = postorder[postorder.length - 1];
        
        int centerInorderIndex = findIndexOfElement(inorder, centerElement);
        
        TreeNode root = new TreeNode(inorder[centerInorderIndex]);
        
        int[] leftInorder = Arrays.copyOfRange(inorder, 0, centerInorderIndex);
        int[] rightInorder = Arrays.copyOfRange(inorder, centerInorderIndex+1, inorder.length);
        
        int[] leftPostorder = Arrays.copyOfRange(postorder, 0, leftInorder.length);
        int[] rightPostorder = Arrays.copyOfRange(postorder, leftInorder.length, postorder.length - 1);
        
        root.left = buildTree(leftInorder, leftPostorder);
        root.right = buildTree(rightInorder, rightPostorder);
        
        return root;
    }
    
    private static int findIndexOfElement(int[] array, int element) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == element) return i;
        }
        return -1;
    }
}