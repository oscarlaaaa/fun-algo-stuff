// 2023-01-10 (prefix-sum)
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        /*
            input: brick wall with n rows of bricks
            output: the minimum number of crossed bricks when drawing a vertical line

            notes:
            - prefix sum approach?
            - count frequencies of values
            - greatest frequency would be how many bricks we can skip
            - time = O(n) where n=number of bricks
            - space = O(m) where m=total size of bricks in a row

            approach:
            - prefix-sum the input vectors, and count frequencies throughout
            - count occurrences and find the greatest frequency
            - return the number of bricks - greatest frequency
        */
        int m = wall.size(), maxEdges = 0;
        unordered_map<int, int> edgePositions;
        for (int i=0; i<m; i++) {
            int n = wall[i].size(), total = 0;
            for (int j=0; j<n-1; j++) {
                total += wall[i][j];
                edgePositions[total]++;
                maxEdges = max(maxEdges, edgePositions[total]);
            }
        }
        return m - maxEdges;
    }
};
