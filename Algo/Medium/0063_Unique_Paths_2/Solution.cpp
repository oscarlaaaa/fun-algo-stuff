// 2022-05-19
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.front().front() == 1 || obstacleGrid.back().back() == 1)
            return 0;
        
        vector<vector<int>> reachable;
        for (int i=0; i<obstacleGrid.size(); i++) {
            vector<int> row;
            for (int j=0; j<obstacleGrid[i].size(); j++) {
                row.push_back(0);
            }
            reachable.push_back(row);
        }
        
        reachable[0][0] = 1;
        for (int i=0; i<obstacleGrid.size(); i++) {
            for (int j=0; j<obstacleGrid[i].size(); j++) {
                if (obstacleGrid[i][j] == 0 && reachable[0][0] > 0) {
                    if (i+1 < obstacleGrid.size() && obstacleGrid[i+1][j] == 0) {
                        reachable[i+1][j] += reachable[i][j];
                    }
                    if (j+1 < obstacleGrid[i].size() && obstacleGrid[i][j+1] == 0) {
                        reachable[i][j+1] += reachable[i][j];
                    }
                }
            }
        }
        return reachable.back().back();
    }
};