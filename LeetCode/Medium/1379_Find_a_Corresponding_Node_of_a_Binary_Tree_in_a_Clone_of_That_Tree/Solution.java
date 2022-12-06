class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

// 2022-05-13
class Solution {
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        if (original == target) return cloned;
        
        TreeNode answer = null;
        if (original.left != null)
            answer = getTargetCopy(original.left, cloned.left, target);
        if (answer == null && original.right != null)
            answer = getTargetCopy(original.right, cloned.right, target);
        return answer;
    }
}