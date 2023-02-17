class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2023-02-16 (inorder traversal)
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        """
        input: a binary search tree
        output: the minimum difference between values of any two nodes in a tree

        notes:
        - we can perform inorder traversal of the BFS and use a global variable
          to track the last value we've encountered
            - traverse the left side first, then check if cur val - last val is less than
              the minimum difference
            - then we assign last val as our cur val and recurse down the right side
        - this way, we limit the space we use up to just the stack size (height of tree)
        
        analysis:
        - time = O(v) where v=number of nodes
        - space = O(h) where h=the height of the tree
        """
        last_val = -10**5
        min_diff = 10**5
        def inorderDFS(node):
            nonlocal last_val
            nonlocal min_diff
            if node.left:
                inorderDFS(node.left)

            min_diff = min(min_diff, node.val - last_val)
            last_val = node.val

            if node.right:
                inorderDFS(node.right)

        inorderDFS(root)
        return min_diff
            