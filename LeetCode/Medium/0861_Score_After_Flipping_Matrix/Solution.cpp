// 2023-04-26
class Solution {
public:
    void flipRow(vector<vector<int>>& grid, int row) {
        for (int i=0; i<grid[0].size(); i++)
            grid[row][i] = !grid[row][i];
    }
    void flipCol(vector<vector<int>>& grid, int col) {
        for (int i=0; i<grid.size(); i++)
            grid[i][col] = !grid[i][col];
    }
    int matrixScore(vector<vector<int>>& grid) {
        /*
        notes:
        - based on the scoring, we kinda generate assumptions on what'd be most optimal
        - we'd first want to ensure that the first bits are all 1s; the only way to ensure
          this is to flip the rows of every 0 in the first column, as flipping the entire column
          can negatively impact other 1s in the first column
        - then, to maintain our greatest sig bits, we only flip columns if the column total is
          less than what it'd be if we've flipped it
        
        analysis:
        - time = O(m*n)
        - space = O(1)
        */
        int m = grid.size(), n = grid[0].size();
        for (int j=0; j<n; j++) {
            int colTotal = 0;
            for (int i=0; i<m; i++) {
                // always flip rows so that the first col is all 1s
                if (j == 0 && grid[i][j] == 0) {
                    flipRow(grid, i); 
                } 
                colTotal += grid[i][j];
            }
            // if we're not at the first col, flip cols if more 0s than 1s
            if (j > 0 && m-colTotal > colTotal)
                flipCol(grid, j);
        }

        // tally up our stuff
        int total = 0;
        for (int i=0; i<m; i++) {
            int num = 0;
            for (int j=0; j<n; j++) {
                num = (num << 1) | grid[i][j];
            }
            total += num;
        }

        return total;
    }
};