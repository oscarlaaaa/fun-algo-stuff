// 2023-10-29 (bits)
class Solution {
public:
    int memo[10000] = {0};
    int countBits(int val) {
        if (memo[val] != 0)
            return memo[val];

        int remaining = val, bits=0;
        while (remaining > 0) {
            bits += remaining&1;
            remaining = remaining >> 1;
        }
        memo[val] = bits;
        return bits;
    }
    vector<int> sortByBits(vector<int>& arr) {
        /*
        notes:
        - probably write a custom comparator for this
            - count # of bits, or actual value
        
        analysis:
        - time = O(nlogn)
        - space = O(1)
        */
        
        sort(arr.begin(), arr.end(), [](const int a, const int b) {
            int aBits = countBits(a), bBits = countBits(b);
            if (aBits == bBits) {
                return a<b;
            }
            return aBits< bBits;
        });
        return arr;
    }
};
