// 2022-11-20 (tabulation)
class Solution {
public:
    int climbStairs(int n) {
        /*
        input: number of steps to reach the top
        output: number of ways you can reach the top

        approach:
        - create a 1d array of length (n+1), where each element is the 
          number of ways to reach that step
            - all initialized to 0 except the 0th index
        - iterate through the array, and for each space:
            - add the current value to the space ahead, and 2 spaces ahead
        - return the nth index of the array
        */
        vector<int> stepsToReach(n+1, 0);
        stepsToReach[0] = 1;
        for (int i=0; i<n; i++) {
            stepsToReach[i+1] += stepsToReach[i];
            if (i+2 <= n)
                stepsToReach[i+2] += stepsToReach[i];
        }
        return stepsToReach[n];
    }
};

// 2022-11-20 (memoization)
class Solution {
public:
    vector<int> memo = vector<int>(46, -1);
    int climbStairs(int n) {
        /*
        input: number of steps to reach the top
        output: number of ways you can reach the top

        approach:
        - initialize a memoization table that stores how many ways there
          are to reach each value below n
        - if n == -1, then return 0
        - if n == 0, then return 1
        - if n is in the memo table, return the stored value
        - else, store the recursive call of n-1 and n-2 for n and return it
        */
        if (n == -1) return 0;
        if (n == 0) return 1;
        if (memo[n] != -1) return memo[n];
        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};