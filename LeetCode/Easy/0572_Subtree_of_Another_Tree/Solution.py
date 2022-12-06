from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-12-14 (recursive DFS)
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root:
            return False
        
        if root.val == subRoot.val:
            if self.check_match(root, subRoot):
                return True
        
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
    
    def check_match(self, root, subroot):
        if not root or not subroot:
            return root == subroot
        
        if root.val == subroot.val:
            return self.check_match(root.left, subroot.left) and self.check_match(root.right, subroot.right)
        else:
            return False

## 2022-10-24 (DFS)
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def matchingTrees(node1, node2=subRoot):
            if not node1 or not node2:
                return not node1 and not node2
            if node1.val != node2.val:
                return False
            return matchingTrees(node1.left, node2.left) and matchingTrees(node1.right, node2.right)
        
        stack = [root]
        while stack:
            cur = stack.pop()
            if not cur:
                continue
            if cur.val == subRoot.val and matchingTrees(cur):
                return True
            stack += [cur.left, cur.right]
        
        return False