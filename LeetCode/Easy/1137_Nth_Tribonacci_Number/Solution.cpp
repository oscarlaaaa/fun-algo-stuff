// 2023-01-29 (dp tabulation)
class Solution {
public:
    int tribonacci(int n) {
        /*
            input: an integer n
            output: the nth tribonnaci number

            notes:
            - trib[n] = trib[n-1] + trib[n-2] + trib[n-3]
            - trib[0] = 0
            - trib[1] and trib[2] = 1

            approach:
            - initialize an array of size n+1
            - initialize trib[0], [1], and [2]
            - for loop starting from 3 to n
                - trib[i] = trib[i-1] + trib[i-2] + trib[i-3]
            - return trib[n] at the end
        */
        int trib[n+1];
        trib[0] = 0;
        if (n > 0) trib[1] = 1;
        if (n > 1) trib[2] = 1;
        for (int i=3; i<=n; i++) {
            trib[i] = trib[i-1] + trib[i-2] + trib[i-3];
        }
        return trib[n];
    }
};