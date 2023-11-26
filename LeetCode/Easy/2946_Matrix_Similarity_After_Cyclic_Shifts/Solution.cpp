// 2023-11-25 (brute)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int additional = ((k/n) + 1)*n;
                int jj = (i&1 ? (j+k)%n : (j+additional-k)%n);
                if (mat[i][j] != mat[i][jj]) {
                    return false;
                }
            }
        }
        return true;
    }
};
