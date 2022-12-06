from typing import *

## 2022-05-18  holy this is a dank solution
## thanks to https://stackoverflow.com/questions/11218746/bridges-in-a-connected-graph/11221469#11221469 
class Solution:
    count = 0
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        ## build graph
        adj_list = [set() for _ in range(n)]
        for con in connections:
            adj_list[con[0]].add(con[1])
            adj_list[con[1]].add(con[0])
        
        critical = []
        order = [-1 for _ in range(n)] ## order of visitation
        low = [-1 for _ in range(n)]   ## lowest order # node reachable
        for i in range(n):
            if order[i] == -1:
                self.dfs(adj_list, i, i, order, low, critical)
        
        return critical
    
    def dfs(self, adj_list, prev, cur, order, low, critical):
        ## mark down what order you find the nodes in
        order[cur] = Solution.count
        Solution.count += 1
        
        ## set lowest reachable node to current order id FOR NOW
        low[cur] = order[cur]
        
        for neigh in adj_list[cur]:
            if order[neigh] == -1: ## not visited yet
                self.dfs(adj_list, cur, neigh, order, low, critical)
                
                ## propogate lowest down the traversal order
                low[cur] = min(low[cur], low[neigh])
                
                ## if neighbour's lowest is unchanged, that means it doesn't
                ## loop back to any prior-visited nodes so we can say that
                ## there is a critical connection between [i, neigh]
                if low[neigh] == order[neigh]:
                    critical.append([cur, neigh])
                    
            ## if we're not backtracking along the same path, update low val
            elif neigh != prev: 
                low[cur] = min(low[cur], order[neigh])
