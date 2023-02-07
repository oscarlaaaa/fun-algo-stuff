// 2022-04-13 
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if (s.length() < p.length()) {
            return new ArrayList<Integer>();
        }
        // p.length determines how far you parse in s
        // loop until s.length - (p.length - 1)
        int stopIndex = s.length() - (p.length() - 1);
        HashMap<Character, Integer> map = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        
        // Build hashmap of p
        for (int i = 0; i < p.length(); i++) {
            map.put(p.charAt(i), map.getOrDefault(p.charAt(i), 0) + 1);
        }
        
        HashMap<Character, Integer> windowMap = new HashMap<>();
        for (int j = 0; j < p.length(); j++) {
            windowMap.put(s.charAt(j), windowMap.getOrDefault(s.charAt(j), 0) + 1);
        }
        for (int i = 0; i < stopIndex; i++) {
            boolean found = map.equals(windowMap);
            // sliding window ==> p.length 
            // Build hashmap to check
            if (found) {
                System.out.print(i + " ");
                ans.add(i);
            }
            
            windowMap.put(s.charAt(i), windowMap.get(s.charAt(i))-1);
            if (windowMap.get(s.charAt(i)) == 0) {
                windowMap.remove(s.charAt(i));
            }
            if (i + p.length() < s.length()) {
                windowMap.put(s.charAt(i+p.length()), windowMap.getOrDefault(s.charAt(i+p.length()), 0) + 1);
            }
        }
        return ans;
    }
}