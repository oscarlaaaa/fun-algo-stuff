// 2023-12-31 (last one of the year)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        /*
        notes:
        - iterate through and record first occurrence of each char
        - if we find previously-encountered char, calc the distance between the
          two and record down if max length
        - use std::array for lower overhead

        analysis:
        - time = O(n)
        - space = O(1)
        */
        int n = s.length(), maxLength = -1;
        std::array<int, 26> seen;
        seen.fill(-1);
        for (int i=0; i<n; i++) {
            int pos = s[i]-'a';
            if (seen[pos] == -1) {
                seen[pos] = i;
            } else {
                maxLength = std::max(maxLength, i-seen[pos]-1);
            }
        }
        return maxLength;
    }
};