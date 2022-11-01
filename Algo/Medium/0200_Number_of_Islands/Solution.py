from typing import *

## 2022-12-11 (DFS)
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        for x in range(0, len(grid)):
            for y in range(0, len(grid[x])):
                if grid[x][y] == "1":
                    self.exploreLand(grid, x, y)
                    count += 1
        return count
        
    def exploreLand(self, grid, x, y):
        
        if x < 0 or y < 0 or x >= len(grid) or y >= len(grid[x]) or grid[x][y] == "0":
            return
        
        grid[x][y] = "0"
        
        self.exploreLand(grid, x+1, y)
        self.exploreLand(grid, x, y+1)
        self.exploreLand(grid, x-1, y)
        self.exploreLand(grid, x, y-1)

## 2022-11-1 (DFS)
class Solution:
    directions = [(0,1), (1,0), (-1,0), (0,-1)]
    def numIslands(self, grid: List[List[str]]) -> int:
        """
        input: grid of "1" (land) or "0" (water)
        output: number of islands

        - an island = land connected vertically/horizontally

        approach:
        - iterate through every cell, and if land:
            - DFS with to find all connected islands
            - change from land to water after visiting
        - return the num of times we've had to DFS
        """
        def sink_island(grid, x, y):
            grid[x][y] = '0'
            for i, j in Solution.directions:
                if 0 <= x+i < len(grid) and 0 <= y+j < len(grid[0]) and \
                    grid[x+i][y+j] == '1':
                    sink_island(grid, x+i, y+j)

        islands = 0
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    sink_island(grid, i, j)
                    islands += 1
        return islands