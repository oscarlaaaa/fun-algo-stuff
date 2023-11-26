// 2023-11-26
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        /*
        notes:
        - can re-arrange columns but not rows
        - m*n < 10k, so it's too large to brute force
            - number of permutations = n!
        - cum sum each column?
        - actually we might be able to semi-brute-force this?
            - start at row 0 and collect all columns with 1 at row 0
            - record the area
            - from that set, collect all with 1 at row 1,2,...i recording area each step
            - repeat starting at every row
            - time = O(mnn)
            - nvm this TLEs tf outta here
        - cumsum for consecutive vals within each column
            - we can then sort each row according to their cumsum vals and iterate through
            - greedily find the area at each step! this is a cool approach
                - sort to order each row by greatest to least (in terms of consecutive vals)
        
        analysis:
        - time = O(m*nlogn)
        - space = O(1)
        */
        int m = matrix.size(), n = matrix[0].size();
        for (int j=0; j<n; j++) {
            for (int i=1; i<m; i++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = matrix[i-1][j]+1;
                }
            }
        }

        int maxArea = 0;
        for (vector<int>& row : matrix) {
            sort(row.rbegin(), row.rend());
            int maxVal = row[0];
            for (int i=0; i<n; i++) {
                maxVal = min(maxVal, row[i]);
                maxArea = max(maxArea, maxVal*(i+1));
            }
        }
        return maxArea;
    }
};