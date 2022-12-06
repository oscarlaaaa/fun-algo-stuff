// 2022-06-03 (backtracking)
class Solution {
public:
    int size;
    
    int totalNQueens(int n) {
        this->size = n;
        vector<vector<char>> board;
        for (int i=0; i<n; i++) {
            vector<char> row(n, '.');
            board.push_back(row);
        }
        vector<bool> validCol(n, true);
        
        return countNQueens(board, 0, validCol);
    }
    
    int countNQueens(vector<vector<char>> &board, int row, vector<bool> &validCol) {
        if (row == this->size) return 1;
        
        int count = 0;
        for (int i=0; i<this->size; i++) {
            if (validCol[i] && validSpace(board, row, i)) {
                validCol[i] = false;
                board[row][i] = 'Q';
                count += countNQueens(board, row+1, validCol);
                validCol[i] = true;
                board[row][i] = '.';
            }
        }
        return count;
    }
    
    bool validSpace(vector<vector<char>> &board, int row, int col) {
        if (row == 0) return true;
        
        for (int i=1; i<=row; i++) {
            if (col+i < this->size && board[row-i][col+i] == 'Q' ||
                col-i >= 0 && board[row-i][col-i] == 'Q')
                return false;
        }
        return true;
    }
};