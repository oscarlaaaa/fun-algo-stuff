from typing import *

## 2022-11-02 (DFS)
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        """
        input: list of edges
        output: edge to remove to turn the graph into a tree (last in input if tie)

        - tree = graph without cycles
        - need to detect what edge causes a cycle, and return it

        approach:
        - detect and record the cycle of nodes (DFS?)
            - need to record last seen node since it's undirected
        - choose the latest edge that is in the cycle and return
        """
        neighbors = [[] for _ in range(len(edges)+1)]
        for x, y in edges:
            neighbors[x].append(y)
            neighbors[y].append(x)
        
        def DFS(node, path, seen):
            nonlocal neighbors
            nonlocal cycle_path
            if cycle_path:
                return
            if node in seen:
                path.append(node)
                cycle_path = path[path.index(node):]
                return
            
            seen.add(node)
            path.append(node)
            for n in neighbors[node]:
                if len(path) < 2 or path[-2] != n:
                    DFS(n, path, seen)
            seen.remove(node)
            path.pop()
            
        cycle_path = None
        DFS(1, [], set())
        want = set([(cycle_path[i], cycle_path[i+1]) for i in range(len(cycle_path)-1)])
        for x, y in reversed(edges):
            if (x, y) in want or (y, x) in want:
                return (x, y)

        return []
        