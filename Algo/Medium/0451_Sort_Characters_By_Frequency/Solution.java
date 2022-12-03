import java.util.*;

// 2021-10-21
class Solution {
    public String frequencySort(String s) {
        Map<String, String> freq = new HashMap<String, String>();
        List<String> chars = new ArrayList<String>();
        
        for (int i = 0; i < s.length(); i++) {
            String current = Character.toString(s.charAt(i));
            if (!freq.containsKey(current)) {
                chars.add(current);
                freq.put(current, current);
            } else {
                freq.put(current, freq.get(current) + current);
            }
        }
        
        chars.sort((a, b) -> freq.get(b).length() - freq.get(a).length());
        
        StringBuilder output = new StringBuilder();
        
        for (int i = 0; i < chars.size(); i++) {
            output.append(freq.get(chars.get(i)));
        }
        
        return output.toString();
        
    }
}