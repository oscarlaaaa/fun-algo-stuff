// 2022-05-22
class Solution {
public:
    int howManySubstrings(string &s, int left, int right) {
        int substrings = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--; 
            right++;
            substrings++;
        }
        return substrings;
    }
    
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count += howManySubstrings(s, i, i);
            if (i != 0)
                count += howManySubstrings(s, i-1, i);
        }
        return count;
    }
};