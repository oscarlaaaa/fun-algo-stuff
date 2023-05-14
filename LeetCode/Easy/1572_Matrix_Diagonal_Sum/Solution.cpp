// 2023-05-13
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        /*
        notes:
        - we only want to sum up diagonal values
        - corners are when x or y is 0 or n-1
        - center pieces are when x == y or x+y == n-1

        analysis:
        - time = O(n^2) where n=length of mat
        - space = O(1)
        */
        int n = mat.size();
        int total = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == j || i+j == n-1)
                    total += mat[i][j];
            }
        }
        return total;
    }
};