// 2022-12-27 (greedy approach)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        /*
            input: list of int (basically bool) where 1 = someone sitting, 0 = empty
            output: maximum distance to the closest person from a chosen seat

            notes:
            - looks kinda simple? basically counting consecutive empty seats and finding
              the closest distance (seat count / 2)
            - is this really just that??? huh
            - edge cases would be the ends, which it'd then be the number of empty seats

            approach:
            - iterate through the seats
            - flag for the first empty section so we know to mark first distance as
              the first consecutive row of empties
            - afterwards, just iterate and count num of empties, and distance would be ceil(seats/2)
            - if we finish on an empty, then mark the last distance as the last consecutive row of empties
            - keep track of our current maximum closest distance all the while and return at end
        */
        int n = seats.size();
        int empties = 0, maxDist = 1;
        bool firstSeats = true;
        for (int takenSeat : seats) {
            if (takenSeat) {
                maxDist = max(maxDist, firstSeats ? empties : (int) ceil((1.0*empties)/2));
                firstSeats = false;
                empties = 0;
            } else {
                empties++;
            }
        }
        maxDist = max(maxDist, empties);
        return maxDist;
    }
};