// 2023-01-01
class Solution {
public:
    vector<string> splitIntoWords(string s) {
        int n = s.length();
        vector<string> words;
        int i = 0;
        while (i < n) {
            int start = i;
            while (i<n && s[i] != ' ') i++;
            words.push_back(s.substr(start, i-start));
            while (i<n && s[i] == ' ') i++;
        }
        return words;
    }
    
    bool wordPattern(string pattern, string s) {
        /*
            input: a string pattern, and a string 
            output: whether the string matches the pattern

            approach:
            - split s into a vector of strings
            - iterate through the vector and pattern concurrently, and assign words to their respective
              pattern letters and vice versa
            - if there is a mismatch, return false
            - return true at the end
        */
        int n = pattern.length();
        vector<string> words = splitIntoWords(s);
        if (words.size() != n)
            return false;
        
        unordered_map<string, char> wordToPattern;
        unordered_map<char, string> patternToWord;
        for (int i=0; i<words.size(); i++) {
            if (wordToPattern.count(words[i]) && patternToWord.count(pattern[i])) {
                if (wordToPattern[words[i]] != pattern[i] || patternToWord[pattern[i]] != words[i])
                    return false;
            } else if (wordToPattern.count(words[i]) || patternToWord.count(pattern[i])) {
                return false;
            } 

            wordToPattern[words[i]] = pattern[i];
            patternToWord[pattern[i]] = words[i];   
        }
        return true;
    }
};