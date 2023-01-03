// 2023-01-01
class Solution {
public:
    bool detectCapitalUse(string word) {
        /*
            input: a word
            output: whether the word's usage of capitals is correct

            approach:
            - create a function to determine whether a letter is a capital or not (letter-'A' between 0 and 26)
            - iterate through the letter, and check for these three conditions:
              - number of capitals = 1 and it's the first one
              - number of capitals = 0
              - number of capitals = length of word
            - return false otherwise
        */
        int n = word.length(), capitalCount = 0;
        for (char c : word) {
            if ('A' <= c && c <= 'Z')
                capitalCount++;
        }
        return capitalCount == 0 || capitalCount == n || 
            capitalCount == 1 && 'A' <= word[0] && word[0] <= 'Z';
    }
};