// 2021-10-14
public class Solution {
    public int numIslands(char[][] grid) {
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int totalIslands = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                totalIslands += traverseLand(grid, visited, i, j);
            }
        }
        return totalIslands;
    }
    
    private static int traverseLand(char[][] grid, boolean[][] visited, int x, int y) {
        if (x >= grid.length || y >= grid[0].length || x < 0 || y < 0) return 0;
        if (grid[x][y] == '0') return 0;
        if (visited[x][y]) return 0;
        visited[x][y] = true;
        
        traverseLand(grid, visited, x + 1, y);
        traverseLand(grid, visited, x, y + 1);
        traverseLand(grid, visited, x - 1, y);
        traverseLand(grid, visited, x, y - 1);
        
        return 1;
    }
} 
    
