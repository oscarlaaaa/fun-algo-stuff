// 2021-06-08
class Solution {
    public String longestCommonPrefix(String[] strs) {
        
        // Initial reference string
        String reference = strs[0];
        
        // Loops through list of strings
        for (int i = 1; i < strs.length; i++) {
            
            // If checked string length < reference string length, preemptively set new reference string length
            if (reference.length() > strs[i].length())
                reference = reference.substring(0, strs[i].length());
            
            // Loops through characters in the string
            for (int x = 0; x < strs[i].length(); x++) {
                
                // Ensures the loop only checks up to length of reference string
                if (x >= reference.length()) break;
                
                // If characters dont match, set new reference string
                if (Character.compare(reference.charAt(x), strs[i].charAt(x)) != 0) {
                    reference = reference.substring(0, x);
                    break;
                }

            }
        }
        
        return reference;
    }
}