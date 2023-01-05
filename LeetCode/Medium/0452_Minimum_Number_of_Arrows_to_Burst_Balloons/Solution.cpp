// 2022-01-04 (sort then greedy)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        /*
            input: coordinates of a balloon along an x plane [start, end]
            output: the minimum number of arrows to burst all balloons

            notes:
            - can shoot an arrow to cover an entire column
            - just need to shoot the points with the most overlap?
            - can probably sort then do a greedy approach
              - since we need to pop every balloon, can sort by start then end,
                shoot an arrow at the end of the first balloon, and go forward until
                we can't pop any more?

            approach:
            - sort points by start, then end
            - initialize total arrows used = 0
            - iterate through the points and do:
              - increment total arrows by 1
              - mark the end of the Qcurrent balloon as where we're shooting
              - iterate forward until we reach a balloon that won't be popped
                - as we iterate, see if we need to adjust our shot backwards to hit it
                  (because we sort, any amount of adjustment can hit our previous balloons)
            - return total arrows
        */
        int n = points.size();
        int arrows = 0, idx = 0;
        sort(points.begin(), points.end());
        while (idx < n) {
            arrows++;
            int shoot = points[idx][1];
            while (idx < n && points[idx][0] <= shoot) {
                shoot = min(shoot, points[idx][1]);
                idx++;
            }
        }
        return arrows;
    }
};
