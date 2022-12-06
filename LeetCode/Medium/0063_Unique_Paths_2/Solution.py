from typing import *

## 2022-05-14
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[-1][-1] == 1:
            return 0
        
        num_paths = [[0 for _ in range(len(obstacleGrid[0]))] for i in range(len(obstacleGrid))]
        num_paths[0][0] = 1
        
        for i in range(len(num_paths)):
            for j in range(len(num_paths[i])):
                if obstacleGrid[i][j] == 1 or num_paths[i] == 0:
                    continue
                
                if i+1 < len(num_paths):
                    num_paths[i+1][j] += num_paths[i][j]
                if j+1 < len(num_paths[i]):
                    num_paths[i][j+1] += num_paths[i][j]
        
        return num_paths[-1][-1]
    