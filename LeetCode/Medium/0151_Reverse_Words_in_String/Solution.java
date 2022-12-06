import java.util.*;

// 2021-10-19 (stack approach)
class Solution {
    public String reverseWords(String s) {
        if (s.length() == 1) return s;
        
        Scanner scan = new Scanner(s);
        Deque<String> stack = new ArrayDeque<String>();
        
        while (scan.hasNext()) {
            stack.addLast(scan.next());
        }
        
        StringBuilder sb = new StringBuilder();
        while (stack.size() > 0) {
            sb.append(stack.getLast());
            stack.removeLast();
            if (stack.size() > 0) sb.append(" ");
        }
        return sb.toString();
    }
}