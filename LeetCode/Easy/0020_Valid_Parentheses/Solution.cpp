// 2022-08-31 (stack)
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
        };
        
        deque<char> stack;
        for (int i=0; i<s.length(); i++) {
            if (brackets.count(s[i]) != 0) {
                stack.push_back(s[i]);
            } else {
                if (stack.size() == 0 || brackets[stack.back()] != s[i])
                    return false;
                
                stack.pop_back();
            }
        }
        
        return stack.size() == 0;
    }
};