// 2023-11-26 (tabulation dp)
class Solution {
public:
    int knightDialer(int n) {
        /*
        notes:
        - lame so we probably need to keep a set of valid moves
        - this is DP so i think we just keep a record of # possible ways to reach a # and
          apply the count of the space to every other reachable number n times
            - was thinking of keeping n keypads but honestly don't need bc we only need
              current and previous state
        - probably modulus each time wtf this is lame

        analysis:
        - time = O(n)
        - space = O(1)
        */
        int MOD = 1000000007;
        vector<vector<int>> keypad = {{1,1,1}, {1,1,1}, {1,1,1}, {-1,1,-1}};
        vector<vector<int>> intermediateKeypad = {{0,0,0}, {0,0,0}, {0,0,0}, {-1,0,-1}};
        vector<pair<int, int>> possibleMoves = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};

        for (int i=1; i<n; i++) {
            vector<vector<int>> keypadNext = intermediateKeypad;
            for (int r=0; r<4; r++) {
                for (int c=0; c<3; c++) {
                    if (keypad[r][c] <= 0) {
                        continue;
                    }

                    // apply all current possible moves to any reachable spaces
                    for (auto [ri, ci] : possibleMoves) {
                        int newR = r+ri, newC = c+ci;
                        if (newR >= 0 && newR < 4 && newC >= 0 && newC < 3 && keypadNext[newR][newC] != -1) {
                            keypadNext[newR][newC] = (1LL * keypadNext[newR][newC] + keypad[r][c])%MOD;
                        }
                     }
                }
            }

            // replace our keypad
            keypad = move(keypadNext);
        }

        int total = 0;
        for (int i=0; i<4; i++) {
            for (int j=0; j<3; j++) {
                if (keypad[i][j] <= 0) {
                    continue;
                }
                
                total = (1LL * total + keypad[i][j])%MOD;
            }
        }
        return total;
    }
};