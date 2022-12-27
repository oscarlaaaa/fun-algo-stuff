// 2022-12-26 (binary search)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /*
            input: n piles of bananas, and h hours
            output: minimum int K that we can finish all bananas within h hours

            notes:
            - we kinda need to simulate it, but we need to find the best val within a range
            - most liekly binary search since finding within a range

            approach:
            - find min and max values within piles
            - set up binary search where the middle value would be how many we eat
              per hour
            - 'simulate' eating by running through the pile and seeing if our hours are sufficient
            - lowest value we finish eating thru will be our return
        */
        int smallest = 1;
        int largest = *max_element(piles.begin(), piles.end());
        while (smallest < largest) {
            int eat = smallest + (largest-smallest)/2;
            int hoursLeft = h;
            for (int pile : piles) {
                hoursLeft -= ceil((1.0 * pile)/eat);
            }
            if (hoursLeft >= 0) {
                largest = eat;
            } else {
                smallest = eat+1;
            }
        }
        return smallest;
    }
};