import java.util.*;

// 2021-06-22
class Solution {
    private List<String> output;
    
    private void recursion(StringBuilder sb, int leftbag, int rightbag) {
        
        // base-case; when both bags are empty
        if (leftbag + rightbag == 0) {
            output.add(sb.toString());
        }
            
        // can always put left brackets while keeping the parenthesis valid, so recurse if left bag is not empty
        if (leftbag > 0) {
            StringBuilder sbclone = new StringBuilder(sb.toString());
            sbclone.append('(');
            recursion(sbclone, leftbag - 1, rightbag);
        }

        // can only put right brackets if there is more left ones in than right; recurse if so and if right bag is not empty
        if (leftbag < rightbag && rightbag > 0) {
            StringBuilder sbclone = new StringBuilder(sb.toString());
            sbclone.append(')');
            recursion(sbclone, leftbag, rightbag - 1);
        }
    }
        
    public List<String> generateParenthesis(int n) {
        StringBuilder sb = new StringBuilder();
        output = new ArrayList<String>();
        
        recursion(sb, n, n);
        
        return output;
    }
}