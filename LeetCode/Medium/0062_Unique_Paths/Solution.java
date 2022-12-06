// 2021-10-09 (memoization)
class Solution {
    public int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        
        int[][] maxPossible = new int[m + 1][n + 1];
        return findPaths(m, n, maxPossible);
    }
    
    private static int findPaths(int m, int n, int[][] maxPossible) {
        if (m == 0 || n == 0) return 0;
        if (m == 1 || n == 1) return 1;
        if (maxPossible[m][n] != 0) return maxPossible[m][n];
        
        int totalPaths = 0;
        totalPaths += findPaths(m-1, n, maxPossible);
        totalPaths += findPaths(m, n-1, maxPossible);
        
        maxPossible[m][n] = totalPaths;
        return totalPaths;
    }
}

// 2021-11-16 (tabulation)
class Solution2 {
    public int uniquePaths(int m, int n) {
        int[][] tab = new int[m+1][n+1];
        tab[1][1] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i+1 <= m) {
                    tab[i+1][j] += tab[i][j];
                }
                if (j+1 <= n) {
                    tab[i][j+1] += tab[i][j];
                }
            }
        }
        return tab[m][n];
    }
}