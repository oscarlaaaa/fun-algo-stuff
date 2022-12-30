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