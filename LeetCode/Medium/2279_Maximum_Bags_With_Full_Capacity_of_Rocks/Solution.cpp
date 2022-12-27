// 2022-12-27 (sortin)
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        /*
            input: list of int max bag capacities, list of int current rocks, int additional rocks to put
            output: max number of full bags after placing rocks into bags

            notes:
            - seems like sort since we'd want to fill the bags that are closest to being full first

            approach:
            - sort in increasing order based on difference between capacity and rocks
            - fill as many bags with our rocks as we can
            - return how many bags are full (likely where we run out of rocks)
        */
        int n = capacity.size();
        vector<int> space(n);
        for (int i=0; i<n; i++) {
            space[i] = capacity[i]-rocks[i];
        }

        sort(space.begin(), space.end());

        int rocksRemaining = additionalRocks;
        for (int i=0; i<n; i++) {
            rocksRemaining -= space[i];
            if (rocksRemaining < 0) 
                return i;
        }

        return n;
    }
};