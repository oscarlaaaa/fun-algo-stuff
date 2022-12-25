// 2022-12-24 (tabulation DP)
class Solution {
public:
    int MOD = 1e9 + 7;
    int numTilings(int n) {
        /*
            input: n for a 2xn sized board
            output: number of ways we can tile it with dominos and trominos

            notes:
            - definitely DP
            - starting from the left, you have 2 options:
              - vertical domino
              - 2 horizontal dominoes
              - tronimo orientation as L
              - tronimo orientation as upsidedown L
            
            approach:
            - iterative DP using 2 vectors: one for an even right-side ( | ), 
              and one for an irregular right-side ( L )
            - starting from 0, we can iterate through both vectors
            - flat side can place:
              - one vertical domino 1 step forward
              - 2 horizontal dominoes 2 steps forward
              - tronimo 2 steps forward (2 diff ways into the other vector as it becomes irreg)
            - irregular side can place:
              - one horizontal domino 1 step forward
              - one tronimo 1 step forward (into the other vector as it becomes flat)
            - return the last value of the flat side vector
        */

        vector<int> flat(n+1), irreg(n+1);
        flat[0] = 1;
        for (int i=0; i<n; i++) {
            // add piece to flats
            flat[i+1] = (flat[i+1] + flat[i]) % MOD;
            if (i+2 <= n) {
                flat[i+2] = (flat[i+2] + flat[i]) % MOD;
                irreg[i+2] = (irreg[i+2] + flat[i]*2) % MOD;
            }

            // add piece to irregs
            irreg[i+1] = (irreg[i+1] + irreg[i]) % MOD;
            flat[i+1] = (flat[i+1] + irreg[i]) % MOD;
        }
        return flat[n];
    }
};