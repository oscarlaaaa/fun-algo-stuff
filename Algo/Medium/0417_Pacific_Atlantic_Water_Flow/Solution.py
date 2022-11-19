from typing import *

## 2021-11-26 (memoized DFS)
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        pacific = list(([False]*len(heights[i])) for i in range(0, len(heights)))
        atlantic = list(([False]*len(heights[i])) for i in range(0, len(heights)))
        
        self.find_flowables(heights, pacific, atlantic)
        return self.find_intersections(pacific, atlantic)
        
    def find_flowables(self, heights, pacific, atlantic):
        for i in range(0, len(heights)):
            for j in range(0, len(heights[i])):
                if i == 0 or j == 0:
                    self.flow_up(heights, atlantic, i, j)
                
                if i == len(heights)-1 or j == len(heights[i])-1:
                    self.flow_up(heights, pacific, i, j)
 
    def flow_up(self, heights, can_reach, i, j):
        current = heights[i][j]
        can_reach[i][j] = True
        
        if i+1 < len(heights) and not can_reach[i+1][j] and current <= heights[i+1][j]:
            heights[i+1][j]
            self.flow_up(heights, can_reach, i+1, j)
        if i-1 >= 0 and not can_reach[i-1][j] and current <= heights[i-1][j]:
            heights[i-1][j]
            self.flow_up(heights, can_reach, i-1, j)
            
        if j+1 < len(heights[0]) and not can_reach[i][j+1] and current <= heights[i][j+1]:
            heights[i][j+1]
            self.flow_up(heights, can_reach, i, j+1)
        if j-1 >= 0 and not can_reach[i][j-1] and current <= heights[i][j-1]:
            heights[i][j-1]
            self.flow_up(heights, can_reach, i, j-1)
   
    def find_intersections(self, pacific, atlantic):
        output = []
        for i in range(0, len(pacific)):
            for j in range(0, len(pacific[i])):
                if atlantic[i][j] and pacific[i][j]:
                    output.append([i, j])
        return output

## 2022-11-02 (memoized DFS but cleaner B))
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        """
        topleft = pacific ocean
        botright = atlantic ocean

        input: heights were height[r][c] = height above sea level
        output: lsit of coordinates where [i,j] is the cell that rainwater can
                flow to both oceans
        
        constraint:
        - 1 <= m and n <= 200
        - no negative heights
        - corners guaranteed to flow to both

        approach:
        - for each cell along i=0 and j=0, flow upwards to cells that can reach the pacific
        - for each cell along i=n-1 and j=m-1, flow upwards to cells that can reach the atlantic
        - record every cell that matches both
        """
        def flow_upwards(heights, x, y, ocean):
            if (x, y) in ocean:
                return
            
            ocean.add((x, y))
            for i, j in [(1,0), (0,1), (-1,0), (0,-1)]:
                if 0 <= x+i < len(heights) and 0 <= y+j < len(heights[0]) and heights[x][y] <= heights[x+i][y+j]:
                    flow_upwards(heights, x+i, y+j, ocean)


        m, n = len(heights), len(heights[0])
        atlantic, pacific = set(), set()
        for i in range(m):
            flow_upwards(heights, i, 0, atlantic)
            flow_upwards(heights, i, n-1, pacific)
        
        for j in range(n):
            flow_upwards(heights, 0, j, atlantic)
            flow_upwards(heights, m-1, j, pacific)
        
        return list(atlantic & pacific)