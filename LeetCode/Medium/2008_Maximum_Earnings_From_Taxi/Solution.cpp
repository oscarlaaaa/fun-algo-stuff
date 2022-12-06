// 2022-12-05 (tabulation dp)
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        /*
            input: n point on a road, rides[start, end, tip]
            output: max money possible

            notes:
            - money earned = end-start + tip
            - n is relatively small, so we can store in an array
            - probably want to sort the array?

            approach:
            - DP, with each value in dp vector representing max money we can earn
              by that spot
            - store all rides using their starting point
            - for each spot, go thru rides that start here and apply the maximum earnable 
              amount to the ride's end points
            - carry previous maximum forward to use later
        */
        vector<vector<pair<int, int>>> rideVals(n+1);
        for (vector<int> &ride : rides) {
            rideVals[ride[0]].push_back({ride[1], ride[2]});
        }
        vector<long long> dp(n+1, 0);
        for (int i=0; i<n; i++) {
            for (auto &[end, tip] : rideVals[i]) {
                dp[end] = max(dp[end], dp[i] + end - i + tip);
            }
            dp[i+1] = max(dp[i], dp[i+1]);
        }
        return dp[n];
    }
};