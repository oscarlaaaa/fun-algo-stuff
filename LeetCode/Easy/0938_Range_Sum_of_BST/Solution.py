from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2021-12-13
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if not root:
            return 0
        
        total = self.rangeSumBST(root.left, low, high) + self.rangeSumBST(root.right, low, high)
        
        if root.val >= low and root.val <= high:
            total += root.val
        
        return total