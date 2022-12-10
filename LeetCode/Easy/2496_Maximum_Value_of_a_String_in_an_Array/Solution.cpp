// 2022-12-10 
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        /*
            input: vector of strings
            output: greatest out of numeric strings/string lengths

            approach:
            - loop through the vector of strings
            - calculate the value step by step, or set to -1 if we hit a non-number
            - record if > max (if negative val, then take length of string instead)
        */
        int ans = 0;
        for (string& s : strs) {
            int val = 0;
            for (int i=0; i<s.length() && val>=0; i++) {
                if (!isdigit(s[i])) 
                    val = -1;
                else
                    val = val*10 + (s[i]-'0');
            }
            ans = max(ans, (val == -1 ? (int)s.length() : val));
        }
        return ans;
    }
};