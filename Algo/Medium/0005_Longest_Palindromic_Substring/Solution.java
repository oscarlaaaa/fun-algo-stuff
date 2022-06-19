// 2021-06-18
class Solution {
    public String longestPalindrome(String s) {
        // Checks for base case of length 1
        if (s.length() == 1) return s;
                
        String longest = "";
        
        // For every letter of the string
        for (int i = 0; i < s.length(); i++) {
            
            // Sets back pointer, front pointer
            int back = i - 1;
            int front = i + 1;
            
            // Sets current character as the current longest string
            String currentLongest = "" + s.charAt(i);
            
            // Moves the back slider if back character matches                            
            while (back >= 0 && Character.compare(s.charAt(back), s.charAt(i)) == 0) {
                back--;
            }

            // Moves the front slider if the front character matches
            while (front < s.length() && Character.compare(s.charAt(front), s.charAt(i)) == 0) {
                front++;
            }
            
            // Re-sets the current longest character
            currentLongest = s.substring(back + 1, front);
            
            while (back >= 0 && front < s.length()) {

                // Compares the front and back characters and sets new current longest if length > than old
                if (Character.compare(s.charAt(back), s.charAt(front)) == 0) {
                    if (front - back > currentLongest.length()) {
                        currentLongest = s.substring(back, front + 1);
                    }
                    back--;
                    front++;
                } else {
                    break;
                }
            }
            
            // Sets new output if currentlongest > longest
            if (currentLongest.length() > longest.length())
                longest = currentLongest;
        }
        
        return longest;
    }
}