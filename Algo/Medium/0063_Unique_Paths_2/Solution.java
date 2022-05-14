// 2022-05-14
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid[obstacleGrid.length-1][obstacleGrid[0].length-1] == 1)
            return 0;
        
        int[][] paths = new int[obstacleGrid.length][obstacleGrid[0].length];
        paths[0][0] = 1;
        
        for (int i = 0; i < paths.length; i++) {
            for (int j = 0; j < paths[i].length; j++) {
                if (paths[i][j] == 0 || obstacleGrid[i][j] == 1) continue;
                
                if (j+1 < paths[i].length)
                    paths[i][j+1] += paths[i][j];
                if (i+1 < paths.length)
                    paths[i+1][j] += paths[i][j];
            }
        }
        
        return paths[obstacleGrid.length-1][obstacleGrid[0].length-1];
    }
}