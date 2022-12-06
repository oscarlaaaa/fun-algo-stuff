// 2021-10-08 (memoized DP)
class Solution {
    public int numDecodings(String s) {
        if (s.length() == 1) {
            if (s.equals("0")) {
                return 0;
            }
            return 1;
        }
        int[] memo = new int[s.length()];
        return findDecodeWays(s, 0, memo);
    }
    
    private static int findDecodeWays(String s, int pos, int[] memo) {
        if (pos == s.length()) return 1;
        if (pos > s.length()) return 0;
        if (memo[pos] != 0) return memo[pos];
        int ways = 0;
        char current = s.charAt(pos);

        if (current == '0') {
            return 0;
        } else if (current == '1') {
            ways += findDecodeWays(s, pos+2, memo);
        } else if (current == '2') {
            if (pos + 1 < s.length() && Character.getNumericValue(s.charAt(pos + 1)) >= 0 && Character.getNumericValue(s.charAt(pos + 1)) <= 6) {
                ways += findDecodeWays(s, pos+2, memo);
            } 
        } 
        ways += findDecodeWays(s, pos+1, memo);
        memo[pos] = ways;
        return ways;
    }
}