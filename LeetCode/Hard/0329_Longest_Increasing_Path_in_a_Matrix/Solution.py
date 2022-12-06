from typing import *

## 2022-05-18 wtf why is this a hard level question????
class Solution:
    # directions to iterate
    DIRECTIONS = [[0, 1], [1, 0], [-1, 0], [0, -1]]
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        # memoization
        longest = [[-1 for _ in  range(len(matrix[i]))] for i in range(len(matrix))]
        
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if longest[i][j] == -1:
                    self.dfs(matrix, i, j, longest)
        
        return max([max(row) for row in longest])
        
    def dfs(self, matrix, i, j, longest):
        if longest[i][j] != -1:
            return longest[i][j]
        
        cur_longest = 1
        for direct in Solution.DIRECTIONS:
            newI, newJ = i+direct[0], j+direct[1]
            
            if newI < 0 or newI >= len(matrix) or newJ < 0 or newJ >= len(matrix[i]) \
                or matrix[i][j] <= matrix[newI][newJ]:
                continue
            
            cur_longest = max(cur_longest, 1 + self.dfs(matrix, newI, newJ, longest))
        
        longest[i][j] = cur_longest
        return cur_longest
                