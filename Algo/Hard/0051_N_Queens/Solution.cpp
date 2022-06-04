// 2022-06-03 (backtracking)
class Solution {
public:
    int size;
    vector<string> options;
    vector<vector<string>> solutions;
    
    vector<vector<string>> solveNQueens(int n) {
        this->size = n;
        for (int i=0; i<n; i++) {
            string output = "";
            for (int j=0; j<n; j++) {
                if (j == i) output += 'Q';
                else output += '.';
            }
            this->options.push_back(output);
        }
        
        vector<bool> taken(n, false);
        vector<string> board;
        findAllCombos(board, taken);
        return this->solutions;
    }
    
    void findAllCombos(vector<string> &board, vector<bool> &taken) {
        if (board.size() == this->size) {
            vector<string> oneSolution = board;
            this->solutions.push_back(oneSolution);
            return;
        }
        
        for (int i = 0; i < this->size; i++) {
            if (taken[i] || badSpot(board, i)) continue;
            
            // run backtracking if valid spot
            board.push_back(this->options[i]);
            taken[i] = true;
            
            findAllCombos(board, taken);
            
            board.pop_back();
            taken[i] = false;
        }
    }
    
    // this is only called for valid columns so we don't need to check it
    bool badSpot(vector<string> &board, int col) {
        if (board.size() == 0) return false;
        // parses diagonally upwards both sides to check if valid
        for (int j = 1; j <= board.size(); j++) {
            if (col+j < this->size && board[board.size()-j][col+j] == 'Q' ||
                col-j >= 0 && board[board.size()-j][col-j] == 'Q')
                return true;
        }
        return false;
    }
};