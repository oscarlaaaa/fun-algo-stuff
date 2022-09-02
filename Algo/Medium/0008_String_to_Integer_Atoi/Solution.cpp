// 2022-09-01
class Solution {
public:
    #define ll long long
    void leftTrim(string &s) {
        s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !isspace(ch);
        }));
    }
    
    int myAtoi(string s) {
        // trim leading whitespace
        leftTrim(s);
        
        // determine sign (or absence of)
        int startIdx = s[0] == '+' || s[0] == '-' ? 1 : 0;
        
        ll curVal = 0;
        for (int i=startIdx; i<s.length(); i++) {
            if (!isdigit(s[i])) 
                break;
            
            curVal *= 10;
            curVal += s[i] - '0';

            // clamp if out of bounds
            if (s[0] == '-' && -curVal <= INT_MIN) {
                curVal = -INT_MAX - 1;
                break;
            } else if (curVal > INT_MAX) {
                curVal = INT_MAX;
                break;
            }
        }
        
        // implicit longlong -> int
        return s[0] == '-' ? -curVal : curVal;
    }
};