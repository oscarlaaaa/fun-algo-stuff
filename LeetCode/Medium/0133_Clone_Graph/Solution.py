# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

## 2022-02-22 
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return node
        
        cloned = dict()
        return self.clone(node, cloned)
    
    def clone(self, node: 'Node', cloned: dict) -> 'Node':
        cloned_node = Node(val=node.val)
        cloned[node] = cloned_node
        cloned_node.neighbors = []
        for neighbour in node.neighbors:
            if neighbour in cloned:
                cloned_node.neighbors.append(cloned[neighbour])
            else:
                cloned_node.neighbors.append(self.clone(neighbour, cloned))
        return cloned_node

## 2022-11-1
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        regular_to_clone = dict()
        stack = [node] if node else []
        while stack:
            cur_node = stack.pop()
            regular_to_clone[cur_node] = Node(cur_node.val)
            for neigh in cur_node.neighbors:
                if neigh in regular_to_clone:
                    continue
                stack.append(neigh)
        
        for reg, clone in regular_to_clone.items():
            for neigh in reg.neighbors:
                clone.neighbors.append(regular_to_clone[neigh])
        
        return regular_to_clone.get(node)
        