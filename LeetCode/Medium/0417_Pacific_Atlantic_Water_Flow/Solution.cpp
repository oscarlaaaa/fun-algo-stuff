// 2022-08-31 (recursive dfs)
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> canReachPacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> canReachAtlantic(heights.size(), vector<bool>(heights[0].size(), false));
        
        // flow upwards from valid cells
        for (int i=0; i<n; i++) {
            flowUpwards(heights, canReachPacific, i, 0);
            flowUpwards(heights, canReachAtlantic, i, m-1);
        }
        for (int i=0; i<m; i++) {
            flowUpwards(heights, canReachPacific, 0, i);
            flowUpwards(heights, canReachAtlantic, n-1, i);
        }
        
        
        vector<vector<int>> output;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (canReachPacific[i][j] && canReachAtlantic[i][j]) 
                    output.push_back({i, j});
            }
        }
        return output;
    }
    
    void flowUpwards(vector<vector<int>>& heights, vector<vector<bool>>& canReach, int i, int j) {
        if (canReach[i][j])
            return;
            
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        canReach[i][j] = true;
        
        for (vector<int> dir : directions) {
            if (i+dir[0] < 0 || i+dir[0] >= heights.size() || j+dir[1] < 0 || j+dir[1] >= heights[i].size()) 
                continue;
            
            if (heights[i][j] <= heights[i+dir[0]][j+dir[1]])
                flowUpwards(heights, canReach, i+dir[0], j+dir[1]);
        }
    } 
};