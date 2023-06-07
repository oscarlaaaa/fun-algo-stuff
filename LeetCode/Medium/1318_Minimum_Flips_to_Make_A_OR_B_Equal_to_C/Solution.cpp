// 2023-06-06 (bit shifting)
class Solution {
public:
    int minFlips(int a, int b, int c) {
        /*
        notes:
        - looks like we can just process it bit by bit?
        - sum up the lsb of a and b, and see how it compares to lsb of c
            - if lsb of c == 0, then need lsb(a)+lsb(b) flips
            - else, 0 flips if lsb(a)+lsb(b) > 0 or 1 flip if == 0
        - bitshift all numbers and continue until a/b/c are 0

        analysis:
        - time = O(1)
        - space = O(1)
        */
        int flips = 0;
        while (a || b || c) {
            if ((c&1) == 1) {
                flips += (a&1) + (b&1) > 0 ? 0 : 1;
            } else {
                flips += (a&1) + (b&1);
            }
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return flips;
    }
};