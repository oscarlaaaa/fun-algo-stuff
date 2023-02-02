// 2023-02-01
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        /*
            input: a list of words, and a string of how the letters are ordered
            output: whether all of the words are sorted lexicographically

            notes:
            - we could probably just map the letters to values (0 to 25)
            - iterate forward and ensure that it's always increasing or equal?

            approach:
            - initialize an unordered map storing <char, int> 
            - store every letter in order according to its index
            - check each adjacent word pair to see if they're in the correct order

            analysis:
            - time = O(n*m) where n=length of words and m=average length of a word
            - space = O(1) as we always store 26 char-val pairs
        */
        // store char-value pairs
        unordered_map<char, int> values;
        for (int i=0; i<26; i++) {
            values[order[i]] = i;
        }

        // check that each word is equal or greater than the previous
        for (int i=0; i<words.size()-1; i++) {
            if (correctOrder(words[i], words[i+1], values))
                continue;
            return false;
        }
        return true;
    }

    bool correctOrder(string& w1, string& w2, unordered_map<char, int>& vals) {
        int i = 0;
        while (i < w1.length() && i < w2.length()) {
            if (vals[w1[i]] != vals[w2[i]]) 
                return vals[w1[i]] < vals[w2[i]];
            i++;
        }
        return i >= w1.length() ? true : false;
    }
};