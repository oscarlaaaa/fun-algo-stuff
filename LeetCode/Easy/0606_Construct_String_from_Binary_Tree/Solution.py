from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-09-07 (dfs)
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        tree_string = []
        
        def construct_tree_string(root):
            if not root:
                return
            
            tree_string.append(str(root.val))
            
            if root.left or root.right:
                tree_string.append('(')
                construct_tree_string(root.left)
                tree_string.append(')')
            
            if root.right:
                tree_string.append('(')
                construct_tree_string(root.right)
                tree_string.append(')')
        
        construct_tree_string(root)
        return "".join(tree_string)