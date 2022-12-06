// 2022-12-02
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.length(), m = typed.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            char c = name[i];
            int count = 0;
            while (i<n && name[i] == c) {
                i++;
                count++;
            }
            while (j<m && typed[j] == c) {
                j++;
                count--;
            }
            if (count>0) return false;
        }
        return i == n & j == m;
    }
};