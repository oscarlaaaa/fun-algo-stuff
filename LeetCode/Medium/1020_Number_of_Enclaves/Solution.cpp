// 2023-04-08 (BFS)
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        /*
        notes:
        - 0 is water
        - 1 is land
        - want to see which islands are disconnected from the edge
            - isn't this basically the same as the other one?
        - what if we just BFS from every edge and convert the land
          tiles into water?
        - can count the total # of land tiles and decrement as we "sink"
          land tiles
        
        analysis:
        - time = O(n*m) where grid size = n*m
        - space = O(n*m) where grid size = n*m
        */
        int lands = 0;
        int m = grid.size(), n = grid[0].size();

        // count land tiles and queue up lands on edges of grid
        deque<pair<int, int>> edgeLands;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1)
                    edgeLands.push_back({i,j});
                if (grid[i][j] == 1) 
                    lands++;
            }
        }

        // BFS from every land tile inwards and decrement land tile count
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (!edgeLands.empty()) {
            auto [x, y] = edgeLands.front();
            edgeLands.pop_front();

            if (grid[x][y] == 0)
                continue;
            
            grid[x][y] = 0;
            lands--;
            for (auto [i,j] : directions) {
                if (x+i >= 0 && x+i < m && y+j >= 0 && y+j < n && grid[x+i][y+j] == 1)
                    edgeLands.push_back({x+i, y+j});
            }
        }
        return lands;
    }   
};