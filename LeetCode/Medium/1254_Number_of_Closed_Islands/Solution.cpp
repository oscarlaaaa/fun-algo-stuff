// 2023-04-08 (BFS)
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        /*
        notes:
        - closed just means disconnected vert/hori from other land
        - can probably BFS or DFS? to find different sections of land
        - BFS is probably cooler B)
        - mark visited portions as seen; count how many sections you
          have to call BFS on
        
        analysis:
        - time = O(n*m) where grid=n*m
        - space = O(n*m) where grid=n*m
        */
        vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        int islands = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i=1; i<m-1; i++) {
            for (int j=1; j<n-1; j++) {
                // skip water tiles
                if (grid[i][j] == 1)
                    continue;

                deque<pair<int, int>> queue = {{i, j}};
                bool atEdge = false;
                while (!queue.empty()) {
                    auto [x, y] = queue.front();
                    queue.pop_front();

                    grid[x][y] = 1; // flip land into water after we've finished with it

                    // if we are at the edge, we aren't surrounded by water
                    if (x == 0 || x == m-1 || y == 0 || y == n-1)
                        atEdge = true;

                    for (auto [a, b] : directions) {
                        if (x+a >= 0 && x+a < m && y+b >= 0 && y+b < n && grid[x+a][y+b] == 0)
                            queue.push_back({x+a, y+b});
                    }
                }
                if (!atEdge)
                    islands++;
            }
        }
        return islands;
    }
};