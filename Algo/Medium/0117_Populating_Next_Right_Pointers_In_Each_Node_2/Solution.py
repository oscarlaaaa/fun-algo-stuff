from typing import *

class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

## 2021-12-14 (iterative)
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        queue = [root, None]
        previous = None
        while len(queue) > 0:
            element = queue.pop(0)
            if not element:
                if not previous:
                    break
                queue.append(None)
            else:
                if element.left:
                    queue.append(element.left)
                if element.right:
                    queue.append(element.right)
                if previous:
                    previous.next = element
            
            previous = element
            
        return root

## 2022-05-12 (recursive)
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        prev_nodes = []
        def connect_children(node, level):
            if not node:
                return
            
            if level >= len(prev_nodes):
                prev_nodes.append(node)
            else:
                prev_nodes[level].next = node
                prev_nodes[level] = node
                
            if node.left:
                connect_children(node.left, level+1)
            if node.right:
                connect_children(node.right, level+1)
        
        connect_children(root, 0)
        return root
