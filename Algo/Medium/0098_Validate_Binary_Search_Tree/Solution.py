from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-04-19
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import math
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.validate(root, -math.inf, math.inf)
        
    def validate(self, root, lo, hi) -> bool:
        if not root:
            return True
        
        if root.val >= hi or root.val <= lo:
            return False
        
        left = self.validate(root.left, lo, root.val)
        right = self.validate(root.right, root.val, hi)
        
        return left and right

# 2022-10-24
#
# input: a BST
# output: boolean whether the BST is valid
# 
# approach:
# - have to ensure that going down the left side has the root as the upper limit
# - going down the right side will have root as the lower limit
# - multi-argument recursive?
#   - holds root, left_bound, right_bound
#   - when going down the left, root.val is the right_bound and any existing lower bound for left
#   - when going down the right, root.val is the left_bound and any existing upper bound for right
#   - any val that violates the bounds returns false
#
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def validateBST(node, lower_bound, upper_bound):
            if not node:
                return True
            
            if (lower_bound is not None and node.val <= lower_bound) or \
                (upper_bound is not None and node.val >= upper_bound):
                return False

            return validateBST(node.left, lower_bound, node.val) and \
                validateBST(node.right, node.val, upper_bound)
        return validateBST(root, None, None)        
