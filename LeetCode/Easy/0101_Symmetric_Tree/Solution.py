from platform import node
from typing import *
from collections import deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-05-29
# starting from the root, create pairs of nodes to traverse both left and
# right sides of the tree. with each pair, we can determine that the left child
# of the right node mirrors the right child of the left node, and vice versa. we 
# traverse down continuing add mirror pairs to our queue, and return false if we
# encounter a non-match. if we traverse the whole tree without issue, then it is
# symmetric.
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        
        queue = deque([[root.left, root.right]])
        while queue:
            x = queue.popleft();
            if not x[0] and not x[1]:
                continue
            
            if (not x[0] or not x[1]) or (x[0].val != x[1].val):
                return False
            
            queue.append([x[0].left, x[1].right])
            queue.append([x[0].right, x[1].left])
        
        return True;