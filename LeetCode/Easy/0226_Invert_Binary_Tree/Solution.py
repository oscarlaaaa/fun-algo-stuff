from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-10-17 (recursive)
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root:       
            root.left, root.right = root.right, root.left
            self.invertTree(root.left)
            self.invertTree(root.right)
            
        return root

## 2023-02-17 (recursive)
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        input: a binary tree
        output: a flipped binary tree (all left/right swapped)

        notes:
        - seems relatively simple; just swap left/right at every node

        complexity:
        - time = O(v) where v=number of nodes
        - space = O(1)
        """
        if root:
            root.left, root.right = root.right, root.left
            self.invertTree(root.left)
            self.invertTree(root.right)
        return root

## 2023-02-17 (iterative)
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        """
        input: a binary tree
        output: a flipped binary tree (all left/right swapped)

        notes:
        - seems relatively simple; just swap left/right at every node
        - we do iterative bc we're cool like that B)
            - takes more space but no risk of overflow from the call stack

        complexity:
        - time = O(v) where v=number of nodes
        - space = O(v) where v=number of nodes
        """
        queue = deque([root] if root else [])
        while queue:
            node = queue[0]
            queue.popleft()

            node.left, node.right = node.right, node.left
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        return root