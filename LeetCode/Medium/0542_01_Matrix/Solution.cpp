// 2023-08-16 (BFS)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        /*
        notes:
        - nearest 0 for each cell
        - we can probably iterate in every direction and count how far we are from the last 0
          or something similar
        - looks p simple for a O(mn) solution
        - actually it's a BFS problem!!! i am rust
        - just queue up each zero and propagate outwards while skipping repeats
        
        analysis:
        - time = O(mn)
        - space = O(mn)
        */
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> nearestZero = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, 0));

        deque<pair<int, int>> queue;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j] == 0) {
                    queue.push_back({i, j});
                    nearestZero[i][j] = 0;
                    visited[i][j] = true;
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!queue.empty()) {
            auto [x, y] = queue.front();
            queue.pop_front();

            for (auto [a, b] : directions) {
                if (inBounds(x+a, y+b, m, n) && !visited[x+a][y+b]) {
                    nearestZero[x+a][y+b] = nearestZero[x][y]+1;
                    visited[x+a][y+b] = true;
                    queue.push_back({x+a, y+b});
                }
            }
        }

        return nearestZero;
    }

    bool inBounds(int x, int y, int m, int n) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
};