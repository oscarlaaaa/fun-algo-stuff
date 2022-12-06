// 2021-11-12
class Solution {
    public boolean isValidSudoku(char[][] board) {
        return areRowsValid(board) && areColumnsValid(board) && areSubboxesValid(board);
    }
    
    private boolean areRowsValid(char[][] board) {
        for (int i = 0; i < board.length; i++) {
            
            boolean[] checked = new boolean[board[i].length + 1];
            for (int j = 0; j < board[i].length; j++) {
                
                if (board[i][j] != '.') {
                    int val = Character.getNumericValue(board[i][j]);
                    if (checked[val]) return false;
                    checked[val] = true;
                }
            }
        }
        return true;
    }
    
    private boolean areColumnsValid(char[][] board) {
        for (int i = 0; i < board[0].length; i++) {
            boolean[] checked = new boolean[board.length + 1];
            for (int j = 0; j < board.length; j++) {
                
                if (board[j][i] != '.') {
                    int val = Character.getNumericValue(board[j][i]);
                    if (checked[val]) return false;
                    checked[val] = true;
                }
            }
        }
        return true;
    }
    
    private boolean areSubboxesValid(char[][] board) {
        for (int i = 0; i < board.length; i += 3) {
            for (int j = 0; j < board[i].length; j += 3) {
                
                boolean[] checked = new boolean[board.length + 1];
                for (int row = i; row < i + 3; row++) {
                    
                    for (int col = j; col < j + 3; col++) {
                        
                        if (board[row][col] != '.') {
                            int val = Character.getNumericValue(board[row][col]);
                            if (checked[val]) return false;
                            checked[val] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
}