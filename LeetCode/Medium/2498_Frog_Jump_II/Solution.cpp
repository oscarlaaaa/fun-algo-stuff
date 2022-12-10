// 2022-12-10 (greedy approach)
class Solution {
public:
    int maxJump(vector<int>& stones) {
        /*
            input: stone positions
            output: smallest jump needed to go to the end and back without repeating stones

            notes:
            - cannot repeat rocks
            - need to go back and forth

            approach:
            - calculate the distance between rocks 2 indices apart and return

            reasoning:
            the only way to minimize the max jump made would be to skip a rock each time.

                example: [1,2,3,10,11,12]
            
            while we may think that going from 3 -> 10 would be the best way to make an
            already-large jump smaller, it actually causes problems for us on the way back
            as we now have to go from 11 -> 2 due to the no repeat clause, which has a greater
            jump distance (9) compared to just going 2 -> 10 (8 length), and then 11 -> 3 (8 length).

            as such, we simply need to check the distance between rocks with a separation of 2, and
            return the smallest value possible from that.
        */
        if (stones.size() == 2) 
            return abs(stones[0] - stones[1]);
        int largest = 0;
        for (int i=0; i<stones.size()-2; i++) {
            largest = max(largest, abs(stones[i] - stones[i+2]));
        }
        return largest;
    }
};