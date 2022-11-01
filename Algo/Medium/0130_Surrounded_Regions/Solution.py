from typing import *


## 2022-11-1 (DFS)
class Solution:
    directions = [(1,0), (0,1), (-1,0), (0,-1)]
    def solve(self, board: List[List[str]]) -> None:
        """
        input: board with 'x' and 'o'
        output: None (modify the board)

        observations
        - 'o' is only not surrounded if it is beside a wall
        - only needs to be 4 directionally surrounded
        - seems to lend itself recursively

        approach:
        - for each cell, dfs if it's an 'o'
            - if it's beside a wall, return false
            - otherwise, recursive call for each edge
            - if all recursive calls are true, then flip

        """
        def in_bounds(board, x, y):
            return 0 <= x < len(board) and 0 <= y < len(board[0])

        def flip_if_surrounded(board, x, y, seen):
            should_flip = True
            stack, done = [(x, y)], []
            while stack:
                done.append(stack.pop())
                x, y = done[-1]
                seen[x][y] = True
                if x == 0 or y == 0 or x == len(board)-1 or y == len(board[0])-1:
                    should_flip = False
                for i, j in Solution.directions:
                    if in_bounds(board, x+i, y+j) and not seen[x+i][y+j] and board[x+i][y+j] == 'O':
                        stack.append((x+i, y+j))
            
            if should_flip:
                for x, y in done:
                    board[x][y] = 'X'

        m, n = len(board), len(board[0])
        seen = [[False for _ in range(n)] for i in range(m)]

        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O' and not seen[i][j]:
                    flip_if_surrounded(board, i, j, seen)
        
