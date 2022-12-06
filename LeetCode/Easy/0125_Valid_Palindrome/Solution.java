// 2021-07-14
class Solution {
    public boolean isPalindrome(String s) {
        int start = 0;
        int end = s.length() - 1;
        
        while (start < end) {
            
            while (!Character.isLetterOrDigit(s.charAt(start)) && start < end) {
                ++start;
            }
            while (!Character.isLetterOrDigit(s.charAt(end)) && start < end) {
                --end;
            }
            
            if (start >= end) break;

            int diff = Math.abs(Character.toLowerCase(s.charAt(start)) - Character.toLowerCase(s.charAt(end)));
            
            if (diff == 0) {
                ++start;
                --end;
            } else {
                return false;
            }
        }
        return true;
    }
}