from typing import *

## 2022-10-31 (straight simulation)
class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        """
        input: grid of balls falling either way
            - 1: left to right
            - -1: right to left
        
        output: list where list[i] is column that the ball falls out of or -1 if it gets stuck

        approach:
        - need to know which ball falls where
        - ball can only travel down if the adjacent cell matches
            - 1 to the right of 1
            - -1 to the left of -1
        - n sized array to track current ball positions, stuck is removed
        - O(m*n) if we start the balls at the top, and iterate thru the entire thing
        """
        m, n = len(grid), len(grid[0])
        balls = [i for i in range(n)]
        for row in grid:
            for i in range(n):
                # no ball in this column
                if balls[i] == -1:
                    continue

                cur_pos = balls[i]
                if cur_pos < n-1 and row[cur_pos] == row[cur_pos+1] == 1: 
                    balls[i] += 1 # right
                elif cur_pos >= 1 and row[cur_pos] == row[cur_pos-1] == -1:
                    balls[i] -= 1 # left
                else: 
                    balls[i] = -1 # stuck
                    
        return balls
