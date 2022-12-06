// 2022-10-09
class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.length() < 2) return "";

        int n = palindrome.length();
        // only check half since if first half doesn't have an 'a', then
        // the second wouldn't either since it's a palindrome
        for (int i=0; i<n/2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        // if palindrome is entirely 'a's, then optimal solution would be to
        // change the last value into a 'b'
        palindrome[n-1] = 'b';
        return palindrome;
    }
};