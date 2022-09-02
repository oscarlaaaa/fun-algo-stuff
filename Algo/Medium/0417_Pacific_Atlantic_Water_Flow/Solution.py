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
