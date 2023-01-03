// 2022-12-02 (brute force)
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        /*
            input: list of strings
            output: how many columns to delete (non-lexicographical order)

            notes:
            - all strings in the list have the same length

            approach:
            - brute force iterate?? is there another way to do this? not really
            - iterate through each column ensuring that they're in sorted order
              - if not sorted, increment a counter
        */
        int m = strs.size(), n = strs[0].length();
        int badColumns = 0;
        for (int i=0; i<n; i++) {
            for (int j=1; j<m; j++) {
                if (strs[j-1][i] > strs[j][i]) {
                    badColumns++;
                    break;
                }
            }
        }
        return badColumns;
    }
};