
// 2022-05-15 (DFS with recursive implementation) TLE
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        
        dfs(grid, grid.size()-1, grid[0].size()-1, -1);
        return (grid[0][0] >= 0 ? -1 : -grid[0][0]);
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y, int steps) {
        if (x >= grid.size() || x < 0 || y >= grid[x].size() || y < 0 || grid[x][y] == 1)
            return;
        
        if (grid[x][y] != 0 && steps <= grid[x][y])
            return;
        
        grid[x][y] = steps;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i==0 && j==0) continue;
                dfs(grid, x+i, y+j, steps-1);
            }
        }
    }
};

// 2022-05-15 (BFS with an iterative queue implementation)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid[grid.size()-1][grid[0].size()-1] == 1)
            return -1;
        
        // push bottom-right and initialize to -1
        queue<pair<int, int>> q;
        q.push({grid.size()-1, grid[0].size()-1});
        grid[grid.size()-1][grid[0].size()-1] = -1;
        
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    // skip current position
                    if (i==0 && j==0) continue;
                    
                    int x = cur.first + i;
                    int y = cur.second + j;
                    
                    // continue if we're out of bounds or if we're going to hit an obstacle
                    if (x >= grid.size() || x < 0 || y >= grid[x].size() || y < 0 || grid[x][y] == 1)
                        continue;
                    
                    // if we can get a shorter path to the next square from our current position,
                    // then change # of steps to reach next square and queue it for exploration
                    if (grid[x][y] == 0 || grid[x][y] < grid[cur.first][cur.second]-1) {
                        grid[x][y] = grid[cur.first][cur.second]-1;
                        q.push({x, y});
                    }
                }
            }
        }
        return (grid[0][0] >= 0 ? -1 : -grid[0][0]);
    }
};