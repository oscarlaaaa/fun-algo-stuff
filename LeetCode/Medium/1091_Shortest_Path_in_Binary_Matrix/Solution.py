from typing import *

## 2021-12-14
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        target_x = len(grid)-1
        target_y = len(grid[0])-1
        
        if grid[0][0] == 1 or grid[target_x][target_y] == 1:
            return -1
        
        grid[0][0] = 1
        queue = []
        queue.append([0, 0, 1])
        
        while len(queue) > 0:
            x, y, length = queue.pop(0)
            if x == target_x and y == target_y:
                return length
            
            self.append_all_directions(x, y, length, grid, queue)
        
        return -1
            
    def append_all_directions(self, x, y, length, grid, queue):
        for i in (-1, 0, 1):
            for j in (-1, 0, 1):
                if i == 0 and j == 0:
                    continue
                    
                if self.is_within_bounds(x+i, y+j, grid) and grid[x+i][y+j] == 0:
                    grid[x+i][y+j] = 1
                    queue.append([x+i, y+j, length+1])
        
    def is_within_bounds(self, x, y, grid):
        return x >= 0 and y >= 0 and x < len(grid) and y < len(grid[0])
    