// 2023-01-20 (recursive backtracking)
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        /*
            input: a string of only digits
            output: all possible valid IP addresses by inserting dots into s

            notes:
            - each num cannot have leading zeroes (otehr than 0 obviously)
            - each number must be between 0 and 255 (inclussive)
            - cannot reorder or remove any digits
            - looks like a backtracking thing?
                - maybe try to find all permutations of 3 dots?
            
            approach:
            - create a recursive function that iterates forward, and finds spots to place dots
                - need to track current position, current dot placements
                - for loop starting from current position, and track the number we have until
                  the number exceeds 255 OR we have leading zeroes
            - find positions to place dots -> craft ip from each one afterwards? or probably craft as we go

            analysis:
            - O(2^n) where n=length of string
            - O(n) where n=length of string
        */
        vector<string> current, output;
        findValidIps(s, 0, current, output);
        return output;
    }

    void findValidIps(string& s, int pos, vector<string>& current, vector<string>& output) {
        if (pos == s.length()) {
            if (current.size() == 4) 
                output.push_back(createIp(current));
            return;
        }

        string val = "";
        for (int i=pos; i<s.length(); i++) {
            if (val == "0") 
                break;

            val += s[i];

            if (stoi(val) > 255) 
                break;

            current.push_back(val);
            findValidIps(s, i+1, current, output);
            current.pop_back();
        }
    }

    string createIp(vector<string>& s) {
        string ip = s[0];
        for (int i=1; i<4; i++) {
            ip += "." + s[i];
        }
        return ip;
    }
};