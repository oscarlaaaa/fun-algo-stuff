## 2021-12-14 (recursive backtracking DFS)
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        possible_paths = []
        self.find_paths(graph, 0, possible_paths, [])
        return possible_paths
    
    def find_paths(self, graph, position, possible_paths, current_path):
        current_path.append(position)
        
        if position == len(graph)-1:
            possible_paths.append(current_path.copy())
        else:
            for neighbour in graph[position]:
                self.find_paths(graph, neighbour, possible_paths, current_path)
        
        current_path.pop()

## 2023-02-16 (recursive backtracking
# class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        """
        input: a DAG
        output: all possible paths from node 0 to node n-1 (any order)

        notes:
        - simple backtracking - just processing every single possibility
        - we'd probably approach this recursively
            - function with a list to track path, a global with our answers
            - recurse down every neighbour until we hit n-1, or until there
              are no other neighbours (acyclic)
            - if we hit n-1, add to our answer list and go backwards
                - pop off our current node to make room for the other paths

        analysis:
        - time = O(e) where e=number of edges in the graph
        - space = O(v) where v=number of vertices (if we don't include answer output)
        """
        answers = []
        
        def findAllPaths(node, graph, path):
            nonlocal answers
            path.append(node)
            
            if node == len(graph)-1:
                answers.append(path[:])
            else:
                for neighbour in graph[node]:
                    findAllPaths(neighbour, graph, path)
            path.pop()
        
        findAllPaths(0, graph, [])
        return answers