// 2022-06-01
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> output;
        for (int i=0; i<matrix[0].size(); i++) {
            vector<int> column;
            for (int j=0; j<matrix.size(); j++) {
                column.push_back(matrix[j][i]);
            }
            output.push_back(column);
        }
        return output;
    }
};