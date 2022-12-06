from typing import *

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

## 2022-08-14
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root.val == p.val or root.val == q.val:
            return root
        
        if root.val > max(p.val, q.val):
            return self.lowestCommonAncestor(root.left, p, q)
        elif root.val < min(p.val, q.val):
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return root

## 2022-10-24 (initial DFS/backtracking)
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        """
        input: bt root, the two nodes we need to find the ancestors for
        output: the node of the lowest common ancestor

        approach:
        - find the path to one node (p)
        - from each 'path' starting from the end (which will be p), we can traverse searching for q
        - return the node we initially branched from once find q
        """
        def findPathToNode(cur, target, cur_path):
            if cur == None:
                return None

            cur_path.append(cur)
            if cur == target:
                return cur_path[:]
            
            left = findPathToNode(cur.left, target, cur_path)
            right = findPathToNode(cur.right, target, cur_path)
            if left or right:
                return left if left else right

            cur_path.pop()
            return None
        
        path_to_p, path_to_q = findPathToNode(root, p, []), findPathToNode(root, q, [])
        len_p, len_q = len(path_to_p), len(path_to_q)
        cur_match = 0
        while cur_match < len_p and cur_match < len_q and path_to_p[cur_match] == path_to_q[cur_match]:
            cur_match += 1
        
        return path_to_p[cur_match-1]

## 2022-10-24 (proper traversal after reading that it is a BST)
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def findPathToNode(cur, target, cur_path):
            if cur == None:
                return None

            cur_path.append(cur)
            if cur == target:
                return cur_path[:]
            
            if target.val < cur.val:
                return findPathToNode(cur.left, target, cur_path)
            else:
                return findPathToNode(cur.right, target, cur_path)

        
        path_to_p, path_to_q = findPathToNode(root, p, []), findPathToNode(root, q, [])
        len_p, len_q = len(path_to_p), len(path_to_q)
        cur_match = 0
        while cur_match < len_p and cur_match < len_q and path_to_p[cur_match] == path_to_q[cur_match]:
            cur_match += 1
        
        return path_to_p[cur_match-1]

## 2022-10-24 (optimized!)
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        """
        input: bt root, the two nodes we need to find the ancestors for
        output: the node of the lowest common ancestor

        approach:
        - traverse down until we reach the center (greater/equal to left, less than/equal to right)
        - return the center (which would be the lowest common ancestor)
        """
        cur = root
        left = p if p.val < q.val else q
        right = q if q.val > p.val else p
        while cur and not (left.val <= cur.val <= right.val):
            cur = cur.right if cur.val < left.val else cur.left
        return cur
            