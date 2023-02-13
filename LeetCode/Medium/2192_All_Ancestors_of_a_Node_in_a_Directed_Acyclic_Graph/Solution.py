## 2023-02-13 (memoized DFS)
class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        """
        input: n for number of nodes, and edges for a directed acyclic graph
        output: a list "answer" where answer[i] = list of ancestors of the ith node sorted

        notes:
        - seems like a DFS kinda situation
        - probably recursive dfs from the leaf nodes and bubble up the list of ancestors?
            - if we do the other way, then we'd have to go over the same spots multiple
            - would also have to ensure that all ancestors get sent down, so
              doesn't seem worth it
        - probably track these edges backwards, and treat it as "all children of a node" instead?
            - would be easier since we can just grab all ancestors then bubble ancestors upwards
            - child --recursive call--> parent is better since we can ensure that all ancestors
              are grabbed
        - utilize memoization to minimize extra work

        analysis:
        - time = O(vlogv) where v=n
        - space = O(v+e) where v=n and e=number of edges
        """
        parents = [[] for _ in range(n)]
        for a, b in edges:
            parents[b].append(a)
        
        ancestors = [set() for _ in range(n)]

        def findAncestors(node, parents):
            nonlocal ancestors

            if ancestors[node]:
                return ancestors[node]
            
            for parent in parents[node]:
                ancestors[node].add(parent)
                ancestors[node].update(findAncestors(parent, parents))

            return ancestors[node]
        
        for i in range(n):
            findAncestors(i, parents)
        
        return [sorted(x) for x in ancestors]
    