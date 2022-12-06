// 2022-11-30
class Solution {
public:
    bool halvesAreAlike(string s) {
        /*
            input: string of even length
            output: whether the 2 halves of the string have the same # of vowels

            notes:
            - contains both upper and lowercase
            - guaranteed to be even length, so there's never a middle letter
            
            approach:
            - set of vowels
            - count for each half and compare for output
        */
        int n = s.length();
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int leftVowels = 0, rightVowels = 0;
        for (int i=0; i<n/2; i++) {
            if (vowels.count(s[i]))
                leftVowels++;
        }
        for (int i=n/2; i<n; i++) {
            if (vowels.count(s[i]))
                rightVowels++;
        }
        return leftVowels == rightVowels;
    }
};