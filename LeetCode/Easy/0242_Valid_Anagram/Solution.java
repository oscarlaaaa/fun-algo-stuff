import java.util.*;

// 2021-06-07 (hashmap)
class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> track = new HashMap<Character, Integer>();
        
        for (int i = 0; i < s.length(); i++) {
            Character x = s.charAt(i);
            if (track.containsKey(x)) {
                track.put(x, track.get(x) + 1);
            } else {
                track.put(x, 1);
            }
        }
        
        for (int i = 0; i < t.length(); i++) {
            Character y = t.charAt(i);
            
            if (track.get(y) == null) return false;
            
            if (track.get(y) > 1) {
                track.put(y, track.get(y) - 1);
            } else {
                track.remove(y);
            }
        }
        
        return (track.size() == 0);
    }
}

// 2021-11-16 (array)
class Solution2 {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        
        int[] counts = new int[26];
        
        for (int i = 0; i < s.length(); i++) {
            int charS = s.charAt(i) - 'a';
            int charT = t.charAt(i) - 'a';
            
            counts[charS]++;
            counts[charT]--;
        }
        
        for (int num : counts) {
            if (num != 0) return false;
        }
        return true;
    }
}
