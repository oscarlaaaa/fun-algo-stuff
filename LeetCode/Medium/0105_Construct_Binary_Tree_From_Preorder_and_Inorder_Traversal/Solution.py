from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-11-09 (recursive)
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        """
        input: preorder traversal and inorder traversal lists
        output: constructed tree

        notes:
        - first value in preorder is always the root
        - can determine values in each side by separating the inorder list by the used value
        
        approach:
        - recursive approach
        - return none if inorder/preorder empty
        - if inorder/preorder length == 1, return a single node
        - otherwise:
            - create node from first val of preorder
            - split preorder and inorder into 2 lists (use inorder to determine vals in preorder)
            - set left as recursive call of left lists, and vice versa
            - return root
        """
        if not inorder or not preorder:
            return None
        
        val = preorder[0]
        idx = inorder.index(val)
        inorder_l, inorder_r = inorder[:idx], inorder[idx+1:]
        preorder_l, preorder_r = preorder[1:len(inorder_l)+1], preorder[len(inorder_l)+1:]

        return TreeNode(val, self.buildTree(preorder_l, inorder_l), self.buildTree(preorder_r, inorder_r))
