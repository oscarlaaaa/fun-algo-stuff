// 2022-11-26
/*
    If we want an even number of pieces, we can accomplish that by using
    only cuts that pass through the entire circle, resulting in n/2 cuts required.
    However, if we want an odd number of pieces with all equal sizes, then we will
    need to use cuts that reach the center of the circle only, resulting in n cuts.
    Our edge case is if we only want 1 piece, to which we don't need to cut it at all
    because a circle by itself counts as a piece.
*/
class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) return 0;
        if (n&1 == 1) return n;
        return n/2;
    }
};