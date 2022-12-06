// 2022-12-02
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*
            input: number of rows
            output: pascal's triangle

            notes:
            - each number is the sum of the 2 numbers directly above it
                - value of cell is always row_above[i-1] + row_above[i]
            
            approach:
            - start with a single row [[1]]
            - for i<n, add i+1 cells to the row
            - then append onto the output
        */
        vector<vector<int>> output = {{1}};
        for (int i=1; i<numRows; i++) {
            vector<int> row;
            for (int j=0; j<=i; j++) {
                int val = 0;
                if (j > 0) val += output[i-1][j-1];
                if (j < i) val += output[i-1][j];
                
                row.push_back(val);
            }
            output.push_back(row);
        }
        return output;
    }
};