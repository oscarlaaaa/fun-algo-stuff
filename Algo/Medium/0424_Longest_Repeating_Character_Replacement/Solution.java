import java.util.*;

// 2021-06-21 (sliding window)
class Solution {
    public int characterReplacement(String s, int k) {
        if (s.length() == 1) return 1;
        
        int max = 0;
        int back = 0;
        int front = 0;
        
        HashMap<Character, Integer> counts = new HashMap<Character, Integer>();
        Character track = s.charAt(0);
        
        while (front < s.length()) {
            if (track.compareTo((Character) s.charAt(front)) != 0) {
                counts.put(s.charAt(front), counts.getOrDefault(s.charAt(front), 0) + 1);
                track = (counts.getOrDefault(track, 0) > counts.get(s.charAt(front)) ? track : s.charAt(front));
            } else {
                counts.put(track, counts.getOrDefault(track, 0) + 1);
            }
            front++;
            
            if (front - back - counts.get(track) > k) {
                counts.put(s.charAt(back), counts.get(s.charAt(back)) - 1);
                back++;
            } 
            max = (front - back > max ? front - back : max); 
        }
        return max;
    }
}