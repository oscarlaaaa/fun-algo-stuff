// 2021-06-10
class Solution {
    public boolean isValid(String s) {
        
        // If string is length 1, only 1 parenthesis so not valid; base case
        if (s.length() == 1) return false;
        
        // Stack to keep track of left parenthesis
        Deque<Character> stack = new ArrayDeque<Character>();
        
        // Keeps track of parenthesis pairs
        Map<Character, Character> checks = new HashMap<Character, Character>();
        checks.put(')', '(');
        checks.put(']', '[');
        checks.put('}', '{');
        
        for (int i = 0; i < s.length(); i++) {
            Character current = s.charAt(i);
            
            // Add the character to the stack if it is a left parenthesis
            if (!checks.containsKey(current)) {
                stack.push(current);
            } else {
                
                // If nothing to pop, then this right parenthesis doesn't have a left one so is invalid
                if (stack.size() == 0) return false;

                // Checks that the previous parenthesis completes the current one
                Character previous = stack.pop();
                if (previous.compareTo(checks.get(current)) != 0) return false;
            }           
            
        }
        
        // If stack size isn't 0 by the end, means parentheses left over so return false
        return stack.size() == 0;
    }
}

// 2021-11-16
class Solution2 {
    public boolean isValid(String s) {
        Map<Character, Character> endBrackets = new HashMap<Character, Character>();
        endBrackets.put('}', '{');
        endBrackets.put(')', '(');
        endBrackets.put(']', '[');
        
        Deque<Character> stack = new ArrayDeque<Character>();
        
        for (int i = 0; i < s.length(); i++) {
            char current = s.charAt(i);
            if (endBrackets.containsKey(current)) {
                if (stack.size() == 0) return false;
                char last = stack.pop();
                if (endBrackets.get(current) != last) return false;
            } else {
                stack.addFirst(current);
            }
        }
        
        return stack.size() == 0;
    }
}