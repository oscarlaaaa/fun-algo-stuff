// 2022-11-22
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
        input: sudoku board - either a number or a '.'
        output: whether the board is valid

        notes:
        - invalid if multiple of the same in the same area
        - can be valid, but not necessarily solvable
        - 3 things to validate: rows, columns, boxes

        approach:
        - use a set to keep track of what was encountered
        - validate rows, then columns, then boxes
        */
        const int LENGTH = board.size();

        // validate rows and cols
        for (int i=0; i<LENGTH; i++) {
            unordered_set<char> seenRow, seenColumn;
            for (int j=0; j<LENGTH; j++) {
                if (board[i][j] != '.') {
                    if (seenRow.count(board[i][j])) return false;
                    seenRow.insert(board[i][j]);
                }

                if (board[j][i] != '.') {
                    if (seenColumn.count(board[j][i])) return false;
                    seenColumn.insert(board[j][i]);
                }
            }
        }

        // validate squares
        // set the bounds for each square 
        // rows = [i,i+3), cols = [j, j+3)
        for (int i=0; i<LENGTH; i+=3) {
            for (int j=0; j<LENGTH; j+=3) {
                unordered_set<char> seenCell;

                // iterate within the bounds of the square
                for (int row=i; row<i+3; row++) {
                    for (int col=j; col<j+3; col++) {
                        if (board[row][col] != '.') {
                            if (seenCell.count(board[row][col])) return false;
                            seenCell.insert(board[row][col]);
                        }
                    }
                }
            }
        }

        return true;
    }
};