import java.util.*;

// 2022-05-14 (backtracking)
class Solution {
    List<int[]> directions;
    
    public boolean exist(char[][] board, String word) {
        this.directions = new ArrayList<>();
        directions.add(new int[]{1, 0});
        directions.add(new int[]{-1, 0});
        directions.add(new int[]{0, 1});
        directions.add(new int[]{0, -1});
        
        char target = word.charAt(0);
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == target) {
                    board[i][j] = '.';
                    boolean found = search(board, i, j, word, 1);
                    if (found) return true;
                    board[i][j] = target;
                }
            }
        }
        return false;
    }
    
    private boolean search(char[][] board, int x, int y, String word, int idx) {
        if (idx >= word.length()) return true;
        
        for (int[] direction : this.directions) {
            int newX = x + direction[0];
            int newY = y + direction[1];
            
            if (newX >= 0 && newX < board.length && newY >= 0 && newY < board[x].length) {
                if (word.charAt(idx) == board[newX][newY]) {
                    board[newX][newY] = '.';
                    boolean found = search(board, newX, newY, word, idx+1);
                    if (found) return true;
                    board[newX][newY] = word.charAt(idx);
                }
            }
        }
        return false;
    }
}