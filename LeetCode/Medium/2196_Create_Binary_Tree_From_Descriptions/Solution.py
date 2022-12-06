from typing import *

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-05-04 (initial solution)
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes = dict()
        no_parent = set()
        
        for d in descriptions:
            if d[0] not in nodes:
                nodes[d[0]] = TreeNode(d[0])
                no_parent.add(d[0])
            if d[1] not in nodes:
                nodes[d[1]] = TreeNode(d[1])
            if d[1] in no_parent:
                no_parent.remove(d[1])
        
        for d in descriptions:
            if d[2] == 1:
                nodes[d[0]].left = nodes[d[1]]
            else:
                nodes[d[0]].right = nodes[d[1]]
        
        root = no_parent.pop()
        return nodes[root]
        