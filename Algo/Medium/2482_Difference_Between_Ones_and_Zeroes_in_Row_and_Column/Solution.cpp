// 2022-11-26
/*
    The problem is simple enough to which we can simply brute-force the solution by
    counting the number of 1s in each row/column, and calculating the diff for each cell.
*/
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> onesRow(m, 0), onesCol(n, 0);
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }
        
        vector<vector<int>> diff;
        for (int i=0; i<m; i++) {
            vector<int> row;
            for (int j=0; j<n; j++) {
                int d = onesRow[i] + onesCol[j] - (m - onesRow[i]) - (n - onesCol[j]);
                row.push_back(d);
            }
            diff.push_back(row);
        }
        return diff;
    }
};