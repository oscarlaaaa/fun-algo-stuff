// 2022-11-20
class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
        input: two strings
        output: whether string s is a subsequence of string t

        notes:
        - s isn't guaranteed to be shorter than t
        - only lowecase letters
        - subsequence != substring, so doesn't have to be consecutive

        approach:
        - pointer at first char of s
        - iterate through t and every time we hit a char that matches what the
          pointer at s is pointing to, increment it
        - return whether the pointer value == length of s
        */

        int curChar = 0;
        for (int i=0; i<t.length() && curChar < s.length(); i++) {
            if (s[curChar] == t[i]) 
                curChar++;
        }
        return curChar == s.length();
    }
};