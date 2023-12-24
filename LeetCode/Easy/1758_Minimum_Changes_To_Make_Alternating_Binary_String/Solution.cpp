// 2023-12-24 (ezpz)
class Solution {
public:
    int minOperations(string s) {
        /*
        notes:
        - minimum # of operations needed to make s alternating
        - string can either start with '1' or '0'; just count # of mismatched
          bits and take the minimum?

        analysis:
        - time = O(n)
        - space = O(1)
        */
        int n = s.length();
        int startZeroDiff = 0, startOneDiff = 0;
        for (int i=0; i<n; i++) {
            bool isOdd = i&1;

            if (s[i] == '0') {
                startZeroDiff += (isOdd ? 1 : 0);
                startOneDiff += (isOdd ? 0 : 1);
            } else {
                startZeroDiff += (isOdd ? 0 : 1);
                startOneDiff += (isOdd ? 1 : 0);
            }
        }
        return std::min(startZeroDiff, startOneDiff);
    }
};