import java.util.*;

// 2921-11-02
class Solution {
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) return "";
        
        Map<Character, Integer> counts = new HashMap<Character, Integer>();
        Set<Character> needs = new HashSet<Character>();
        for (int i = 0; i < t.length(); i++) {
            counts.put(t.charAt(i), counts.getOrDefault(t.charAt(i), 0) + 1);
            needs.add(t.charAt(i));
        }
        
        int left = 0;
        int right = 0;
        String smallest = "";
        
        while (right < s.length() && left <= right) {
            while (right < s.length() && needs.size() > 0) {
                char curChar = s.charAt(right);
                
                if (counts.containsKey(curChar)) {
                    counts.put(curChar, counts.get(curChar) - 1);
                    
                    if (counts.get(curChar) == 0) {
                        needs.remove(curChar);
                    }
                }
                right++;
            }
            
            while (left <= right && needs.size() == 0) {
                if (needs.size() == 0 && (smallest.equals("") || smallest.length() > right - left)) {
                    smallest = s.substring(left, right);
                }
                
                char curChar = s.charAt(left);
                if (counts.containsKey(curChar)) {
                    counts.put(curChar, counts.get(curChar) + 1);
                    
                    if (counts.get(curChar) == 1) {
                        needs.add(curChar);
                    }
                }
                left++;
            }
        }
        return smallest;
    }
}