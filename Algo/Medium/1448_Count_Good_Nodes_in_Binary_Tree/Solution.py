class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-10-29 (stack-based DFS)
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        """
        input: root node
        output: number of good nodes (minimum 1 for root)

        - DFS using a stack
        - record down the node to check, and the maximum val in the path to that node
        - increment good node count if node val < max val in the path
        - add child nodes, with max val being max of old max val and current node val
        """

        good_nodes = 0
        stack = [(root, root.val)]
        while stack:
            cur_node, max_in_path = stack.pop()           
            if cur_node.val >= max_in_path:
                good_nodes += 1
                max_in_path = cur_node.val
            
            if cur_node.left:
                stack.append((cur_node.left, max_in_path))
            if cur_node.right:
                stack.append((cur_node.right, max_in_path))

        return good_nodes