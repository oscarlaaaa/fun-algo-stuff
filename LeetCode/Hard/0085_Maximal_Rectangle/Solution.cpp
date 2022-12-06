// 2022-05-21 (based off of the Maximal Square approach)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // craft an array where every cell represents the largest possible
        // square created with the cell at the bottom-right-most cell
        vector<vector<int>> largestSquares;
        for (int i = 0; i < matrix.size(); i++) {
            vector<int> row;
            for (int j = 0; j < matrix[i].size(); j++) {
                row.push_back(matrix[i][j] == '0' ? 0 : 1);
            }
            largestSquares.push_back(row);
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (largestSquares[i][j] == 1) {
                    largestSquares[i][j] = min(largestSquares[i-1][j-1], 
                                               min(largestSquares[i-1][j], 
                                                   largestSquares[i][j-1])) + 1;
                }
            }
        }
        
        // count of consecutive i-sized squares
        vector<int> consec(min(matrix.size(), matrix[0].size())+1, 0);
        vector<int> maxConsec(min(matrix.size(), matrix[0].size())+1, 0);
        
        // count from left-right
        for (int i = 0; i < matrix.size(); i++) {
            int size;
            for (int j = 0; j < matrix[i].size(); j++) {
                size = largestSquares[i][j];
                consec[size]++;
                
                // if current size is < previous tile's size, then we want to
                // save the max values we have for the current size and bubble the 
                // counts down to size-1. this works because if you have 2 squares
                // of size 5, they can also be counted as 2 squares of size 4/3/.../1
                if (j > 0 && size < largestSquares[i][j-1]) {
                    int prev = largestSquares[i][j-1];
                    while (prev > size) {
                        maxConsec[prev] = max(maxConsec[prev], consec[prev]);
                        consec[prev-1] += consec[prev];
                        consec[prev] = 0;
                        prev--;
                    }
                }
            }
            
            // save all of our current counts and reset the consec vector
            while (size > 0) {
                maxConsec[size] = max(maxConsec[size], consec[size]);
                consec[size-1] += consec[size];
                consec[size] = 0;
                size--;
            }
        }
        
        /// same as above except count from top-bottom
        for (int i = 0; i < matrix[0].size(); i++) {
            int size;
            for (int j = 0; j < matrix.size(); j++) {
                size = largestSquares[j][i];
                consec[size]++;
                if (j > 0 && size < largestSquares[j-1][i]) {
                    int prev = largestSquares[j-1][i];
                    while (prev > size) {
                        maxConsec[prev] = max(maxConsec[prev], consec[prev]);
                        consec[prev-1] += consec[prev];
                        consec[prev] = 0;
                        prev--;
                    }
                }
            }
            while (size > 0) {
                maxConsec[size] = max(maxConsec[size], consec[size]);
                consec[size-1] += consec[size];
                consec[size] = 0;
                size--;
            }
        }
        
        // return the max from the areas of our largest recorded consecutive squares
        int maximum = 0;
        for (int i = 1; i < maxConsec.size(); i++) {
            if (maxConsec[i] > 0)
                maximum = max(maximum, (i*i) + i*(maxConsec[i]-1));
        }
        
        return maximum;
    }
};