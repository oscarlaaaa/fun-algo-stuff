// 2022-09-18 (stack)
class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> stack;
        for (char c : s) {
            if (!stack.empty() && stack.back() == c) {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        
        string output = "";
        for (auto it = stack.begin(); it != stack.end(); it++)
            output += *it;
        return output;
    }
};