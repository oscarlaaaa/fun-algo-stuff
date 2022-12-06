import java.util.*;

//2021-07-21
class Solution {
    public List<String> allPossible;
    public Map<Character, char[]> letters;
    
    private void checkAll(String digits, int pos, StringBuilder sb) {
        
        if (pos >= digits.length()) {
            allPossible.add(sb.toString());
        } else {
            char num = digits.charAt(pos);
            char[] possible = letters.get(num);
        
            for (char val : possible) {
                StringBuilder clone = new StringBuilder(sb.toString());
                clone.append(val);
                checkAll(digits, pos + 1, clone);
            }
        }
        
    }
    
    public List<String> letterCombinations(String digits) {
        allPossible = new ArrayList<String>();
        
        if (digits.length() == 0) return allPossible;
        
        letters = new HashMap<Character, char[]>();
        letters.put('2', new char[]{'a', 'b', 'c'});
        letters.put('3', new char[]{'d', 'e', 'f'});
        letters.put('4', new char[]{'g', 'h', 'i'});
        letters.put('5', new char[]{'j', 'k', 'l'});
        letters.put('6', new char[]{'m', 'n', 'o'});
        letters.put('7', new char[]{'p', 'q', 'r', 's'});
        letters.put('8', new char[]{'t', 'u', 'v'});
        letters.put('9', new char[]{'w', 'x', 'y', 'z'});
        
        checkAll(digits, 0, new StringBuilder());
        return allPossible;
    }
}