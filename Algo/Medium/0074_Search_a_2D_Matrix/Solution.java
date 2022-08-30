class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // navigate to correct row
        int row = 0;
        while (row < matrix.length && matrix[row][matrix[row].length-1] < target) {
            row++;
        }
        
        // if the last element of the last row is still smaller than target, then DNE
        if (row == matrix.length) return false;

        // binary search to find correct column
        int colL = 0;
        int colR = matrix[row].length - 1;
        
        if (matrix[row][colL] == target || matrix[row][colR] == target) return true;
        
        while (colL < colR - 1) {
            int mid = colL + (colR - colL)/2;
            if (matrix[row][mid] < target) {
                colL = mid;
            } else if (matrix[row][mid] > target) {
                colR = mid;
            } else {
                return true;
            }
        }
        return false;      
    }
}