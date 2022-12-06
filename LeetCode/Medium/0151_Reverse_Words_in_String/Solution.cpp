// 2022-11-13 (stack approach)
class Solution {
public:
    string reverseWords(string s) {
        vector<string> word_list;
        stringstream words(s);
        string word;
        while (getline(words, word, ' ')) {
            if (word != "") 
                word_list.push_back(word);
        }

        string output = "";
        for (auto itr=word_list.rbegin(); itr != word_list.rend(); ++itr) {
            if (itr != word_list.rbegin())
                output += " ";
            output += *itr;
        }

        return output;
    }
};