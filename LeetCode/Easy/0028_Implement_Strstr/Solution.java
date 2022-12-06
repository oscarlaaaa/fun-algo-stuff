// 2021-08-27
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) return 0;
        if (needle.length() > haystack.length()) return -1;
        
        for (int i = 0; i < haystack.length() - (needle.length() - 1); i++) {
            String word = haystack.substring(i, i + needle.length());
            if (word.equals(needle)) return i;
        }
        return -1;    
    }
}