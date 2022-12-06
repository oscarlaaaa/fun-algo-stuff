import java.util.*;

// 2021-11-03
class Solution {
    public int uniquePathsIII(int[][] grid) {
        int totalPossibleSteps = 0;
        int[] start = new int[2];
        int paths = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    start[0] = i; 
                    start[1] = j;
                }
                if (grid[i][j] == 0 || grid[i][j] == 2) totalPossibleSteps++;
            }
        }
        paths = walkAround(grid, start[0], start[1], 0, totalPossibleSteps);
        return paths;
    }
    
    private static int walkAround(int[][] grid, int x, int y, int totalSteps, int goal) {
        if (x < 0 || y < 0 || x >= grid.length || y >= grid[0].length) return 0;
        
        if (grid[x][y] == -1) return 0;
        if (grid[x][y] == 2) return (totalSteps == goal ? 1 : 0);
        
        int temp = grid[x][y];
        grid[x][y] = -1;
        
        int up = walkAround(grid, x - 1, y, totalSteps + 1, goal);
        int down = walkAround(grid, x + 1, y, totalSteps + 1, goal);
        int left = walkAround(grid, x, y - 1, totalSteps + 1, goal);
        int right = walkAround(grid, x, y + 1, totalSteps + 1, goal);
        
        grid[x][y] = temp;
        return up + down + left + right;
    }
}