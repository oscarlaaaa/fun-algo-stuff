// 2021-07-25
class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.length() == 0) return true;
        if (t.length() == 0) return false;
        
        int sPos = 0;
        for (int i = 0; i < t.length(); i++) {
            if (s.charAt(sPos) == t.charAt(i)) ++sPos;
            if (sPos >= s.length()) return true;
        }
        
        return false;
    }
}