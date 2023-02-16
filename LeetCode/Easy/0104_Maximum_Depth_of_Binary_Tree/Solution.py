from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-10-15 (recursive)
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return max(1 + self.maxDepth(root.left), 1 + self.maxDepth(root.right))

## 2023-02-15 (iterative)
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        """
        input: the root of a binary tree
        output: the maximum depth of the tree

        notes:
        - root itself has a depth of 1
        - can probably just process all children using BFS and a queue
            - queue will store the node
            - we probably can keep track of a global depth and do batches
              of levels we traverse
        
        analysis:
        - time = O(v) where v=number of nodes
        - space = O(v) where v=number of nodes
        """
        depth = 0
        queue = deque([root] if root else [])
        while queue:
            next_level = deque()
            while queue:
                node = queue[0]
                queue.popleft()
                
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)

            depth += 1
            queue = next_level

        return depth
