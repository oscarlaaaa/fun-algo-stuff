## 2022-08-16 (tabulation)
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        possible_paths = [[0 for _ in range(n)] for i in range(m)]
        
        possible_paths[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i+1 < m:
                    possible_paths[i+1][j] += possible_paths[i][j]
                
                if j+1 < n:
                    possible_paths[i][j+1] += possible_paths[i][j]
        
        return possible_paths[m-1][n-1]