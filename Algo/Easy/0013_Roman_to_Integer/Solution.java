// 2021-06-09
class Solution {
    public int romanToInt(String s) {
        
        // Initialize conversion hashmap
        Map<Character, Integer> conversions = new HashMap<Character, Integer>();
        conversions.put('I', 1);
        conversions.put('V', 5);
        conversions.put('X', 10);
        conversions.put('L', 50);
        conversions.put('C', 100);
        conversions.put('D', 500);
        conversions.put('M', 1000);
        
        int output = 0;
        int previous = 1000;
        for (int i = 0; i < s.length(); i++) {
            if (previous < conversions.get(s.charAt(i)))
                output -= 2 * previous;
            output += conversions.get(s.charAt(i));
            previous = conversions.get(s.charAt(i));
        }
        return output;
        
    }
}