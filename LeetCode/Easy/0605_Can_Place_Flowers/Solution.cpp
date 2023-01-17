// 2023-01-13
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        /*
            input: list of int flowers planted in a flowerbed, and int n flowers to plant
            output: whether we can plant n new flowers into the flowerbed

            notes:
            - no flowers can be adjacent to each other

            approach:
            - iterate through from 1 to n-1
            - if flower[i-1] and flower[i+1] == 0, then we can plant
                - plant by changing flower[i] to 1
                - decrement n if changed
            - return n==0

            analysis:
            - time: O(m) where m=size of flowerbed
            - space: O(1)
        */
        int m = flowerbed.size(), remaining = n;
        for (int i=0; i<m; i++) {
            int flowers = flowerbed[i];
            if (i-1 >= 0) flowers += flowerbed[i-1];
            if (i+1 < m) flowers += flowerbed[i+1];
            if (flowers == 0) {
                flowerbed[i] = 1;
                remaining--;
            }
        }
        return remaining <= 0;
    }
};