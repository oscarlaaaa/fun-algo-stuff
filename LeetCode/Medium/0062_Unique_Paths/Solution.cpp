// 2023-09-02 (tabulation)
class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
        notes:
        - just apply current paths to the right and down
        - tabulation DP ezpz

        analysis:
        - time = O(mn)
        - space = O(mn)
        */
        vector<vector<int>> paths(m+1, vector<int>(n+1, 0));
        paths[0][0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                paths[i+1][j] += paths[i][j];
                paths[i][j+1] += paths[i][j];
            }
        }

        return paths[m-1][n-1];
    }
};