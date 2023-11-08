// 2023-11-07 (math)
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        /*
        notes:
        - we don't even need to simulate this; i think it's just arithmetic
        - just basically need to check whether t is >= the shortest possible path
            - as long as we have more spaces than time, then we can always backtrack to
              let time pass or go diagonal to be more efficient
            - edge case is if we start on the target and t=1

        analysis:
        - time = O(1)
        - space = O(1)
        */
        int xDiff = abs(sx-fx), yDiff = abs(sy-fy);
        if (xDiff + yDiff == 0 && t == 1)
            return false;

        int shortest = max(xDiff, yDiff);
        return t >= shortest;
    }
};
