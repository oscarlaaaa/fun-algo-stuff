// 2023-04-02 (binary search)
class Solution {
public:
    int binary_search(vector<int>& pots, int spell, long long target) {
        int left = 0, right = pots.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            long long val = 1LL * spell * pots[mid];
            if (val >= target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return left;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        /*
        notes:
        - info:
            - 2 positive integer arrays and a positive int
            - success is the minimum product of spell*potion
            - return an int array of length spells where pairs[i] is the number
              of successful pairs with the ith spell
        - gather spell values -> sort potions and sort spell vals -> iterate thru
          with a mono stack?
            - i feel like we need to do some sorting to iterate through cleanly
        - honestly we could even just sort potions and do a binary search to find the index
          every time as well; might be simpler

        analysis:
        - time = O(nlog(m)) where n=spells and m=potions
        - space = O(1) if we don't count output
        */
        int n = spells.size();
        sort(potions.begin(), potions.end(), greater<int>());
        vector<int> numPairs(n);
        for (int i=0; i<n; i++) {
            numPairs[i] = binary_search(potions, spells[i], success);
        }
        return numPairs;
    }
};

// 2023-04-02 (bucket sort)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        /*
        notes:
        - info:
            - 2 positive integer arrays and a positive int
            - success is the minimum product of spell*potion
            - return an int array of length spells where pairs[i] is the number
              of successful pairs with the ith spell
        - we can also just bucket sort our potions and generate a sort of post-prefix sum for
          every possible value of spells 
        - after, just look for the minimum potion power we need for success and grab the post-fix
          sum of that value to find the number of potions >= that power
        - technically O(n) but actually O(1e5n) so it's kinda fat for small sizes

        analysis:
        - time = O(n) where n=spells
        - space = O(1) if we don't count output
        */
        int n = spells.size();

        // bucket sort our potions
        vector<int> buckets(1e5+1), postfix(1e5+1);
        for (int pot : potions) {
            buckets[pot]++;
        }

        // generate post-fix sum
        int potCount = 0;
        for (int i=1e5; i>=0; i--) {
            potCount += buckets[i];
            postfix[i] = potCount;
        }

        vector<int> numPairs(n);
        for (int i=0; i<n; i++) {
            long long minPower = ceil(1.0*success/spells[i]);
            if (minPower > 1e5) // not possible
                continue;
            numPairs[i] = postfix[minPower];
        }
        return numPairs;
    }
};