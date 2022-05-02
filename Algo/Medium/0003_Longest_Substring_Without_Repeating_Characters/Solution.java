import java.util.*;

// 2021-03-25
class Solution {
    public int lengthOfLongestSubstring(String s) {
        List<Character> seen = new ArrayList<Character>();
        int max = 0;
        for (int i=0; i<s.length(); i++) {
            Character x = (Character) s.charAt(i);
            if (!seen.contains(x)) {
                seen.add(x);
            } else {
                int value = seen.size();
                if (value > max) {
                    max = value;
                }
                while (!seen.isEmpty()) {
                    if (seen.get(0).equals(x)) {
                        seen.remove(0);
                        break;
                    } else {
                        seen.remove(0);
                    }
                }
                seen.add(x);
            }
        }
        if (seen.size() > max) {
            max = seen.size();
        }
        return max;
    }
}

// 2021-11-16
class Solution2 {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
        Set<Character> seen = new HashSet<Character>();
        
        int left = 0;
        int right = 0;
        
        while (right < s.length()) {
            if (!seen.contains(s.charAt(right))) {
                seen.add(s.charAt(right));
                right++;
            } else {
                seen.remove(s.charAt(left));
                left++;
            }
            max = max > seen.size() ? max : seen.size();
        }
        return max;
    }
}