// 2023-04-01 (2d tabulation)
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        /*
        notes:
        - goals
            - want to schedule jobs in d days
            - must complete jobs one before the other
            - must complete at least one task every day
            - schedule difficulty is the sum of max difficulties for each day
        - cannot find a schedule for given jobs if more days than available jobs
            - is that the only situation?
        - maybe a 2d memoization array? n+1 x d+1 sized
            - arr[i][j] represents the minimum total difficulty where the top of the
              job pile is job j and we are choosing jobs for day i+1
            - as we iterate thru, keep track of current max to represent the difficulty
              for that day
            - bottom right corner of our arr would be the best possible solution as it means
              our stack is empty and we're done all of the days
        - probably have to double-nest for loop when we iterate through each possible stack
          start since carrying curMax forward without a double for loop would assume that
          we always start at the largest possible stack
        
        analysis:
        - time = O(d*n^2) where n=size of jobDifficulty
        - space = O(d*n)
        */
        int n = jobDifficulty.size();
        vector<vector<int>> minDiff(d+1, vector<int>(n+1, INT_MAX));
        minDiff[0][0] = 0;

        for (int i=0; i<d; i++) {
            // we need to make sure we leave enough tasks for the remaining days
            for (int k=i; k<n-(d-i-1); k++) {
                if (minDiff[i][k] == INT_MAX)
                    continue;
                int curMax = 0;
                for (int j=k; j<n; j++) {
                    curMax = max(curMax, jobDifficulty[j]); // track current max
                    minDiff[i+1][j+1] = min(minDiff[i+1][j+1], minDiff[i][k]+curMax);
                }
            }
        }
        int best = minDiff.back().back();
        return best == INT_MAX ? -1 : best;
    }
};