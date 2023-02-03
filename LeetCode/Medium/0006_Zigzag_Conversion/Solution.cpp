// 2023-02-02
class Solution {
public:
    string convert(string s, int numRows) {
        /*
            input: a string, and an int number of rows
            output: the resulting zigzag pattern read line by line

            notes:
            - looks pretty simple; initialize vector<vector<char>> of size numRows
            - add character by character to vector 0, 1, 2, ...numRows-1, numRows-2, ... 1, 0
              and repeat until we run out of characters
            - append characters from each row togetehr into strings, then append strings together

            analysis:
            - time = O(n) where n=length of s
            - space = O(n) where n=length of s
        */
        if (numRows == 1)
            return s;

        int n = s.length();
        vector<string> rows(numRows);
        int row = 0;
        for (int i=0; i<n; i++) {
            rows[row] += s[i];
            if ((i/(numRows-1)) & 1 == 1) {
                row--;
            } else {
                row++;
            }
        }

        string output = "";
        for (string& row : rows) {
            output += row;
        }
        return output;
    }
};