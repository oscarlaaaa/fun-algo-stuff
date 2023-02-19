# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

## 2023-02-18 (BFS)
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        input: a binary tree
        output: the zig-zag level order traversal of the nodes

        notes:
        - seems relatively straightforward? queue up level by level and process them
          in alternating directions
        - we can also start with an empty tree so b wary of that edge case
        - we can just repeatedly process the level as a stack, since that'd ensure we'd
          do a zig-zag pattern
            - actually we need to keep track of what direction we process as well since
              the order that we add the left/right children is also important
        
        analysis:
        - time = O(v) where v=number of nodes
        - space = O(v) where v=number of nodes
        """
        output = []
        stack = deque([root] if root else [])
        l_to_r = True
        while stack:
            output.append([])
            next_level = deque()
            while stack:
                node = stack[-1]
                stack.pop()
                order = (node.left, node.right) if l_to_r else (node.right, node.left)
                for child in order:
                    if child:
                        next_level.append(child)
                output[-1].append(node.val)
            stack = next_level
            l_to_r = not l_to_r
        return output
