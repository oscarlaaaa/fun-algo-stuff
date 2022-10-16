from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-10-16 (recursive)
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        self.longest = 0
        def countLongestNodePath(root):
            if not root:
                return 0
            
            left = countLongestNodePath(root.left)
            right = countLongestNodePath(root.right)

            self.longest = max(self.longest, left + right + 1)
            return max(left, right) + 1
        
        countLongestNodePath(root)
        return self.longest-1