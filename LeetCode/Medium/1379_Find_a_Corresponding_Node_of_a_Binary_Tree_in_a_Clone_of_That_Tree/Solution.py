class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

## 2022-05-16
class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        if not original:
            return None
        
        if original == target:
            return cloned
        
        left = self.getTargetCopy(original.left, cloned.left, target)
        right = self.getTargetCopy(original.right, cloned.right, target)
        
        return left if left else right
        