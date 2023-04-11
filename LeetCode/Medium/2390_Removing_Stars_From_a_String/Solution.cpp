// 2023-04-10 (stack)
class Solution {
public:
    string removeStars(string s) {
        /*
        notes:
        - looks like a stack approach? since stars can only remove non-star
          characters to the left
        - assuming we will never have more stars than letters?
        - why is this a med?

        analysis:
        - time = O(n) where n=length of s
        - space = O(n) where n=length of s
        */
        vector<char> stack;
        for (char c : s) {
            if (c == '*') {
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }

        string output;
        for (char c : stack)
            output += c;
        return output;
    }
};