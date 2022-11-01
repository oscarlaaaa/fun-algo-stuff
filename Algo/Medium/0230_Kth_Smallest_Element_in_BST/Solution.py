from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2022-04-17
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = [root]
        kth = 0
        last_popped = root
        seen = set()
        while stack and kth < k:
            cur = stack[-1]
            seen.add(cur)    # prevent revisiting
            if cur.left and cur.left not in seen:
                stack.append(cur.left)
            else:
                # if no more non-visited left children, means that cur is the next lowest
                last_popped = stack.pop()
                kth += 1     
                if cur.right and cur.right not in seen:
                    stack.append(cur.right)
            
        return last_popped.val
        
## 2022-10-30 (recursive preorder traversal)
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        def lookForKthSmallest(node, current, k):
            if not node:
                return -1
            
            left = lookForKthSmallest(node.left, current, k)
            if left != -1:
                return left

            current[0] += 1
            if current[0] == k:
                return node.val

            right = lookForKthSmallest(node.right, current, k)
            return right

        return lookForKthSmallest(root, [0], k)
            