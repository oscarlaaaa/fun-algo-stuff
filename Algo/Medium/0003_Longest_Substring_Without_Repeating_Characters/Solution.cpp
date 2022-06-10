// 2022-06-10
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        bitset<256> seen;
        
        int left = 0, right = 0;
        while (right < s.length()) {
            while (seen[s[right]]) {
                seen[s[left]] = 0;
                left++;
            }
            seen[s[right]] = 1;
            right++;
            longest = longest > right-left ? longest : right-left;
        }
        
        return longest;
    }
};