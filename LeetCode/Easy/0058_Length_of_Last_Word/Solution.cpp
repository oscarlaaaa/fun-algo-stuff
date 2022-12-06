// 2022-11-20 (tokenizing)
class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, ' '))
        {
            if (token != "")
                tokens.push_back(token);
        }
        return tokens.size() > 0 ? tokens.back().length() : 0;
    }
};