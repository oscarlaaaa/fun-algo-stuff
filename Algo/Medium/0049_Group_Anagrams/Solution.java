import java.util.*;

// 2021-06-21
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> output = new ArrayList<List<String>>();
        Map<Integer, Integer> patterns = new HashMap<Integer, Integer>();
        
        for (int i = 0; i < strs.length; i++) {
            
            int[] count = new int[26];
            Arrays.fill(count, 0);
            
            for (int j = 0; j < strs[i].length(); j++) {
                count[(strs[i].charAt(j) - 'a')]++;
            }
            
            int insertIndex = patterns.size();
            
            if (patterns.containsKey(Arrays.hashCode(count))) {
                insertIndex = patterns.get(Arrays.hashCode(count));
            }
            
            if (insertIndex == patterns.size()) {
                output.add(insertIndex, new ArrayList<String>());
                patterns.put(Arrays.hashCode(count), insertIndex);
            }
            output.get(insertIndex).add(strs[i]);
        }
        return output;
    }
}
