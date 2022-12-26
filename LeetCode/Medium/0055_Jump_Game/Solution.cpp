// 2022-12-25 (greedy)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*
            input: list of ints where list[i] = max jump length from this position
            output: whether you can reach the last index

            notes:
            - may seem like DP, but i feel like we can get a greedy approach going
            - maybe keeping track of how much "distance" we're able to jump?
              - decrementing our possible distance each step, unless our current
                index has a greater possible distance

            approach:
            - keep track of distance remaining
            - iterate through the list
              - if distance remaining < current position's jump dist, then reassign
              - iterate forward and subtract 1 from distance
            - if we ever have 0 after assigning jump dist, then we fail and return false
            - only loop to n-2 as we succeed if we reach n-1
            - return true if we finish iterating
        */
        int n = nums.size();
        int distanceRemaining = 0;
        for (int i=0; i<n-1; i++) {
            distanceRemaining = max(distanceRemaining, nums[i]);
            if (distanceRemaining == 0)
                return false;
            distanceRemaining--;
        }
        return true;
    }
};