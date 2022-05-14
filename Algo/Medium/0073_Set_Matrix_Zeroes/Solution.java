// 2022-05-14
class Solution {
    public void setZeroes(int[][] matrix) {
        boolean topRowIsZeroes = false;
        for (int i = 0; i < matrix[0].length; i++) {
            if (matrix[0][i] == 0) {
                topRowIsZeroes = true;
                break;
            }
        }
        
        boolean leftColIsZeroes = false;
        for (int i = 0; i < matrix.length; i++) {
            if (matrix[i][0] == 0) {
                leftColIsZeroes = true;
                break;
            }
        }
        
        // mark what rows/columns we need to convert at top- and left-most cells
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // check left column if we need to convert the row
        for (int i = 1; i < matrix.length; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < matrix[i].length; j++) {
                    matrix[i][j] = 0;
                }
            }
            // convert current cell if left col is supposed to be zeroed
            if (leftColIsZeroes) matrix[i][0] = 0;
        }
        
        // check top row if we need to convert the column
        for (int j = 1; j < matrix[0].length; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < matrix.length; i++) {
                    matrix[i][j] = 0;
                }
            }
            // convert current cell if top row is supposed to be zeroed
            if (topRowIsZeroes) matrix[0][j] = 0;
        }
    }
}