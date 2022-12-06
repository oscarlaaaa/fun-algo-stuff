// 2022-11-24 (backtracking DFS)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        /*
        input: grid of characters, and a string word
        output: whether the word can be constructed

        approach:
        - backtracking dfs
        - mark used cells with a '.' or something
        */
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] == word[0] && find(board, word, 1, i, j)) return true;
            }
        }
        return false;
    }

    vector<pair<int, int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    bool find(vector<vector<char>>& board, string& word, int idx, int x, int y) {
        if (word.length() == idx) return true;

        char hold = board[x][y];
        board[x][y] = '.';
        for (pair<int, int> d : directions) {
            if (inBounds(x+d.first, y+d.second, board.size(), board[0].size()) && 
                board[x+d.first][y+d.second] == word[idx] && 
                find(board, word, idx+1, x+d.first, y+d.second)) {
                return true;
            }
        }
        board[x][y] = hold;

        return false;
    }
    
    bool inBounds(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
};