// 2022-05-28
/**
 * The approach for this question utilizes a stack to help keep track
 * of previous '(' parentheses to match with incoming ')' brackets. 
 * 
 * We initialize a 'sizes' vector to keep track of our largest length 
 * valid substring, and parse through our string.
 * 
 * With each correctly matched grouping of '()', we look at the following:
 *  - Was there a valid substring immediately before the matched '(' index?
 *  - Are these matched parentheses wrapping a valid substring?
 * 
 * We can take a peek at the 'sizes' index of the index prior to the '(' index
 * to find if there was a valid substring immediately prior, and a peek at the
 * index before the current index to see if we are matching parentheses that wrap
 * around a valid substring. We take the sum of both of these, add 2 to account
 * for the 2 parentheses we are currently matching, and save it in sizes at 
 * the current position to account for potential matches ahead.
 * 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        vector<int> sizes(s.length(), 0);
        deque<int> stack;

        for (int i = 0; i < s.length(); i++) {
            if (stack.empty() || s[i] == '(') {
                stack.push_back(i);
            } else {
                if (s[stack.back()] == '(') {
                    // combine current length with the length of whatever's immediately behind
                    // this substring to get the full valid substring length
                    int behind = stack.back()-1 >= 0 ? sizes[stack.back()-1] : 0;
                    int inside = sizes[i-1];
                    sizes[i] = behind + inside + 2;
                    
                    longest = max(longest, sizes[i]);
                    stack.pop_back();
                } else {
                    // not a match means next substring can't connect with the first, so we can
                    // clear our stack and start anew
                    stack.clear();
                }
            }
        }
        return longest;
    }
};