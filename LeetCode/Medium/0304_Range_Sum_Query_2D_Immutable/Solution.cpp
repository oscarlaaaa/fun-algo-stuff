// 2022-06-03 (Prefix sum approach)
class NumMatrix {
public:
    vector<vector<int>> prefixRight;
    
    NumMatrix(vector<vector<int>>& matrix) {
        this->prefixRight = matrix;
        buildPrefix();
    }
    
    void buildPrefix() {
        for (int i=0; i<this->prefixRight.size(); i++) {
            for (int j=1; j<this->prefixRight[i].size(); j++) {
                prefixRight[i][j] += prefixRight[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i=row1; i<=row2; i++) {
            sum += this->prefixRight[i][col2];
            if (col1 > 0)
                sum -= this->prefixRight[i][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */