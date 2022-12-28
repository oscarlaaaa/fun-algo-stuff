// 2022-12-27 (heap)
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        /*
            input: list of int num of stones in piles, int k
            output: minimum total of stones after applying k operations

            notes:
            - operation = removing floor(piles[i]/2) from a pile
            - most likely be using a heap? since it seems like we'd always
              want to remove the pile with the most stones
            - maybe limit heap to size k as well to minimize insertion time? or nah

            approach:
            - use a PQ as a max heap to store piles
            - keep track of our current total rocks
            - iterate with a for loop from K-1 to 0
              - pop off the top (max) of the heap, remove half of it, and put it back in
              - deduct from our total the amount we took out
            - return our remaining total
        */
        long long totalRocks = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> rockPiles(piles.begin(), piles.end());

        for (int i=0; i<k; i++) {
            int largestPile = rockPiles.top();
            rockPiles.pop();
            totalRocks -= (int) floor(1.0 * largestPile/2);
            rockPiles.push((int) ceil(1.0 * largestPile/2));
        }
        
        return totalRocks;
    }
};