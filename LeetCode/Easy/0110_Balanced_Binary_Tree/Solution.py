from functools import cache
from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 2022-05-08      
class Solution:
    @cache
    def findDepth(self, root) -> int:
        if not root:
            return 0

        left = self.findDepth(root.left)
        right = self.findDepth(root.right)

        return 1 + max(left, right)
    
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        
        if self.isBalanced(root.left) and self.isBalanced(root.right):
            return abs(self.findDepth(root.left) - self.findDepth(root.right)) <= 1
        
        return False

# 2022-05-08 (doesn't require cache)
class Solution:
    def findDepth(self, root) -> int:
        if not root:
            return 0

        left = self.findDepth(root.left)
        right = self.findDepth(root.right)
        
        if left == -1 or right == -1 or abs(left - right) > 1:
            return -1

        return 1 + max(left, right)
    
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        
        depth = self.findDepth(root)
        return depth != -1

# 2022-10-16 (recursive + class variable)
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.balanced = True
        self.check_node_height(root)
        return self.balanced
    
    def check_node_height(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        right = self.check_node_height(root.right)
        left = self.check_node_height(root.left)
        
        self.balanced = self.balanced and abs(right-left) <= 1
        return max(right, left)+1