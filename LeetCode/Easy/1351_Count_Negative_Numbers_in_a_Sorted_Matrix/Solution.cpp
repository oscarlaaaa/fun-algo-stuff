// 2023-06-07
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        /*
        notes:
        - decreasing left-to-right, and top-to-bottom
        - can probably snake around starting from top right?
            - iterate left until positive number hit, then add n-i to count
            - iterate down and repeat

            [[4,3,2,-1],
            [3,2,1,-1],
            [1,1,-1,-2],
            [-1,-1,-2,-3]]

        analysis:
        - time = O(m+n) where length(grid) = m and length(grid[i]) = n
        - space = O(1)
        */
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        int i = 0, j = n;
        while (i < m) {
            while (j > 0 && grid[i][j-1] < 0) {
                j--;
            }
            count += n-j;
            i++;
        }

        return count;
    }
};