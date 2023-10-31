// 2023-10-19
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        /*
        notes:
        - although the easy way would be 2 stacks, we can prob just iterate
        - maybe go from right to left? that way we can treat # as "skip a char"
          instead of "backspace a char"
        - 2 pointers, and iterate until we hit a non # char
            - every # char is 1 skip we can use
        - iterate until no skips left
        - if chars match, then we good

        analysis:
        - time = O(n)
        - space = O(1)
        */
        int i = s.length()-1, j = t.length()-1;
        while (i >= 0 || j >= 0) {
            int sSkips = 0, tSkips = 0;

            // process backspaces until we hit a non-erased char
            while (i >= 0 && (sSkips > 0 && s[i] != '#' || s[i] == '#')) {
                if (s[i] == '#') {
                    sSkips++;
                } else {
                    sSkips--;
                }
                i--;
            }
            while (j >= 0 && (tSkips > 0 && t[j] != '#' || t[j] == '#')) {
                if (t[j] == '#') {
                    tSkips++;
                } else {
                    tSkips--;
                }
                j--;
            }

            if (i >= 0 && j >= 0 && s[i] != t[j])
                return false;
            i--;
            j--;
        }
        return i == j;
    }
};