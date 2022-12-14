// 2022-12-12 (iterative DP)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        /*
            input: 2d array of integers
            output: the minimum sum from falling down the matrix

            notes:
            - when falling, you can only go diagonally left/right, or below
            - array is NxN sized (square)
            - most likely DP as you can break it into subproblems

            approach:
            - create a 2d vector to hold values of "minimum sum possible at vector[i][j]"
            - initialize first row with first row of matrix, and rest of it as INT_MAX
            - iterate through row by row
                - for each cell, assign the fallable cells below it with the minimum sum of
                  (current sum + that cell's original value) vs the current value
            - take the minimum of the bottom row and return
        */
        int n = matrix.size();
        vector<vector<int>> minimumSums(n, vector<int>(n, INT_MAX));
        minimumSums[0] = matrix[0];
        for (int i=0; i<n-1; i++) {
            for (int j=0; j<n; j++) {
                // fall to the left
                if (j-1 >= 0)
                    minimumSums[i+1][j-1] = min(minimumSums[i+1][j-1], minimumSums[i][j]+matrix[i+1][j-1]);

                // fall center
                minimumSums[i+1][j] = min(minimumSums[i+1][j], minimumSums[i][j]+matrix[i+1][j]);

                // fall to the right
                if (j+1 < n)
                    minimumSums[i+1][j+1] = min(minimumSums[i+1][j+1], minimumSums[i][j]+matrix[i+1][j+1]);
            }
        }

        return *min_element(minimumSums.back().begin(), minimumSums.back().end());
    }
};