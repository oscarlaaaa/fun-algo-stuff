from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-05-14
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        def traverseAndSumTree(node, depth, deepest_sum):
            if not node:
                return
            
            if depth > deepest_sum[0]:
                deepest_sum[0] = depth
                deepest_sum[1] = node.val
            elif depth == deepest_sum[0]:
                deepest_sum[1] += node.val
            
            traverseAndSumTree(node.left, depth+1, deepest_sum)
            traverseAndSumTree(node.right, depth+1, deepest_sum)
            return deepest_sum[1]
            
        return traverseAndSumTree(root, 0, [0, 0])
