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

// 2023-06-05 (BFS)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        /*
        notes:
        - probably iterating while flipping 0s into 1s to prevent backtracking
        - we should use BFS as well for shortest path
        - check if top left cell is even available in the beginning
        - mark cells before we queue to prevent queuing the same cell multiple times

        analysis:
        - time = O(n^2) where n=length of grid
        - space = O(n^2) where n=length of grid
        */
        if (grid[0][0] == 1)
            return -1;
        
        int n = grid.size();
        deque<pair<pair<int, int>, int>> queue = {{{0,0}, 1}};
        grid[0][0] = 1;
        
        while (!queue.empty()) {
            auto [x, y] = queue.front().first;
            int dist = queue.front().second;
            queue.pop_front();

            if (x == n-1 && y == n-1)
                return dist;

            for (int i=-1; i<=1; i++) {
                for (int j=-1; j<=1; j++) {
                    if (i == 0 && j == 0 || x+i < 0 || y+j < 0 || x+i >= n || y+j >= n)
                        continue;
                    
                    if (grid[x+i][y+j] == 0) {
                        queue.push_back({{x+i, y+j}, dist+1});
                        grid[x+i][y+j] = 1;
                    }
                }
            }
        }
        return -1;
    }
};