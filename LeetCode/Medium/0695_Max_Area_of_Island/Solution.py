from typing import *

## 2022-11-1 (DFS)
class Solution:
    directions = [(1,0), (0,1), (-1,0), (0,-1)]
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        """
        input = grid of 1s (land) and 0s (water)
        output = largest island

        approach:
        - for each piece of land in the grid, sink it and all connected lands and count
        - record the greatest count and return at the end
        """
        def islands_sank(grid, x, y):
            grid[x][y] = 0
            area = 1
            for i, j in Solution.directions:
                if 0 <= x+i < len(grid) and 0 <= y+j < len(grid[0]) and grid[x+i][y+j] == 1:
                    area += islands_sank(grid, x+i, y+j)
            return area
        
        max_area = 0
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    max_area = max(max_area, islands_sank(grid, i, j))
        
        return max_area
