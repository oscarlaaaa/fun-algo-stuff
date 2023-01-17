// 2023-01-16 (prefix-sum)
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        /*
            input: a binary string s
            output: the minimum number of bit flips to make it monotone increasing

            notes:
            - can either flip 0 -> 1, or 1 -> 0
            - i think we can approach it using a cum-sum approach?
                - basically going right to left counting how many 0 -> 1 flips we need
                  to make it monotone increasing
                - repeat the same for left to right for 1 -> 0 flips
                - find the minimum total num of flips
            
            approach:
            - create 2 int vectors for prefix sums
            - iterate left-to-right, and track how many 1->0 flips we use
            - repeat for right-to-left, tracking 0->1
            - iterate through the prefix sums, and find the minimum total flips where
              prefix1[i] + prefix2[i] = total flips if we leave the ith bit untouched
            - return the minimum

            analysis:
            - time = O(n) where n = length of string
            - space = O(n) where n = length of string
        */
        int n = s.length();
        vector<int> oneToZero(n), zeroToOne(n);
        for (int i=1; i<n; i++) {
            if (s[i-1] == '1')
                oneToZero[i]++;
            oneToZero[i] += oneToZero[i-1];
        }
        for (int i=n-2; i>=0; i--) {
            if (s[i+1] == '0')
                zeroToOne[i]++;
            zeroToOne[i] += zeroToOne[i+1];
        }
        int minFlips = n;
        for (int i=0; i<n; i++) {
            minFlips = min(minFlips, oneToZero[i]+zeroToOne[i]);
        }
        return minFlips;
    }
};