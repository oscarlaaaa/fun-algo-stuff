from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-10-16 (stack-based)
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        nodes_to_check = [(p, q)]
        while nodes_to_check:
            node1, node2 = nodes_to_check.pop()
            if node1 and node2:
                if node1.val != node2.val:
                    return False
                
                nodes_to_check.append((node1.left, node2.left))
                nodes_to_check.append((node1.right, node2.right))
            elif not node1 and not node2:
                continue
            else:
                return False
        
        return True
            