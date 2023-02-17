## 2023-02-16 (inbound/outbound)
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        """
        input: n vertices, and edges between nodes in a DAG
        output: the smallest set of vertices that reach all nodes in the graph

        notes:
        - isn't this just marking the nodes that do not have any inbound edges?
            - since if everything is connected and it is acyclic, then being able to
              reach the nodes with no inbound edges means we can reach the rest of 
              the graph
        
        analysis:
        - time = O(n) where n=number of nodes
        - space = O(n) where n=number of nodes
        """
        has_inbound = [False for _ in range(n)]
        for _, inbound in edges:
            has_inbound[inbound] = True
        
        return [i for i in range(n) if not has_inbound[i]]