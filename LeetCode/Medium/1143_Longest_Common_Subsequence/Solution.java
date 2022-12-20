// 2021-07-31 (dp memoization)
class Solution {
    
    private String s1;
    private String s2;
    private int[][] seen;

    private int solve(int pos1, int pos2) {
        
        if (pos1 >= s1.length() || pos2 >= s2.length()) {
            return 0;
        }
        
        if (seen[pos1][pos2] != -1) {
            return seen[pos1][pos2];
        }
        
        int skipTopChar = solve(pos1 + 1, pos2);
        
        int dontSkipTop = 0;
        
        int indexOfFirstChar = s2.indexOf(s1.charAt(pos1), pos2);
        if (indexOfFirstChar != -1) {
            dontSkipTop = 1 + solve(pos1 + 1, indexOfFirstChar + 1);
        }
        
        seen[pos1][pos2] = Math.max(skipTopChar, dontSkipTop);
        return seen[pos1][pos2];
    }
        
    public int longestCommonSubsequence(String text1, String text2) {
        s1 = text1;
        s2 = text2;
        seen = new int[s1.length()][s2.length()];
        
        for (int i = 0; i < s1.length(); i++) {
            Arrays.fill(seen[i], -1);
        }
        
        return solve(0, 0);
    }
}