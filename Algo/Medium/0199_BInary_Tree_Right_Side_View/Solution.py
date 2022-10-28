from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-10-27 (dfs starting from right)
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        view = []
        stack = [(root, 1)]
        while stack:
            node, depth = stack.pop()
            if not node:
                continue
            if depth > len(view):
                view.append(node.val)

            stack.append((node.left, depth+1))
            stack.append((node.right, depth+1))
        
        return view