from typing import *

## 2022-11-03 (BFS)
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        """
        input: grid of cells that are empty (0), fresh (1), or rotten (2)
        output: minimum minutes to rot all oranges

        - rotten oranges propagate rot to adjacent oranges
        - max grid size is 10x10

        approach:
        - keep track of num of fresh oranges as you go thru
        - utilize a queue and perform BFS starting from every rotten orange
        - once queue is empty, return minutes if we have no more fresh oranges
        """
        m, n = len(grid), len(grid[0])

        num_fresh = 0
        rotten = deque()  # holds tuple(x coord, y coord, minute it has rotted)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    num_fresh += 1
                if grid[i][j] == 2:
                    rotten.append((i, j, 0))
        
        time = 0
        directions = [(1,0),(0,1),(-1,0),(0,-1)]
        while rotten:
            x, y, minute = rotten.popleft()
            time = max(time, minute)

            for i, j in directions:
                if 0 <= x+i < m and 0 <= y+j < n and grid[x+i][y+j] == 1:
                    grid[x+i][y+j] = 2
                    num_fresh -= 1
                    rotten.append((x+i, y+j, minute+1))
        
        return time if num_fresh == 0 else -1
        