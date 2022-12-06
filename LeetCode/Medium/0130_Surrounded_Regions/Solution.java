// 2021-10-31
class Solution {
    static final char capturedPiece = 'X';
    
    public void solve(char[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] != capturedPiece) {
                    boolean[][] checked = new boolean[board.length][board[i].length];
                    boolean isCaptured = isRegionCaptured(board, i, j, checked);
                    
                    if (isCaptured) {
                        capturePieces(board, checked);
                    } 
                }
            }
        }
    }
    
    private void capturePieces(char[][] board, boolean[][] checked) {
        for (int x = 0; x < checked.length; x++) {
            for (int y = 0; y < checked[x].length; y++) {
                if (checked[x][y]) board[x][y] = capturedPiece;
            }
        }
    }

    
    private boolean isRegionCaptured(char[][] board, int i, int j, boolean[][] checked) {
        if (board[i][j] == capturedPiece || checked[i][j]) return true;
        
        if (i - 1 < 0 || j - 1 < 0 || i + 1 >= board.length || j + 1 >= board[i].length) return false;
        
        checked[i][j] = true;
        
        boolean topCaptured = isRegionCaptured(board, i-1, j, checked);
        boolean botCaptured = isRegionCaptured(board, i+1, j, checked);
        boolean leftCaptured = isRegionCaptured(board, i, j-1, checked);
        boolean rightCaptured = isRegionCaptured(board, i, j+1, checked);
        
        boolean isCaptured = topCaptured && botCaptured && leftCaptured && rightCaptured;
        
        return isCaptured;
    }
}