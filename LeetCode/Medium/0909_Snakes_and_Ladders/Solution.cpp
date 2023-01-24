// 2023-01-23 (tabulation DP)
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        /*
            input: an nxn grid with cells labeled from 1 to n^2 starting bottom-left 
                   and zig-zagging upwards
            output: the least number of moves required to reach square n^2, or -1 if not possible

            notes:
            - start at square 1
            - can move 1-6 spaces forward
            - have to take snakes/ladders if encountered
                - -1 = no snake/ladder, the space you end up at if there is
            - this is DP except with a weird twist
                - the only real issue is how to iterate up the board
            - probably do DP, keeping track of the minimum # of steps to reach each cell
            - don't need to double back for snakes since it's better to skip snakes if possible, and
              if it isnt then we'd be unable to reach the end
            - how to determine the position of a square?
                - n - 1 - (val-1)/n = the row #
                - if row# is an even number, then it's right to left, and vice versa
            
            approach:
            - create an nxn grid of 0s, except grid[n-1][0] is 1
            - iterate upwards using double-nested for loops, except the first loop goes in increments of 2
              and has 2 other loops inside, going right, then left on different columns
                - for each space 1 to 6 spaces ahead, assign the minimum of the space's val and current space+1
                  to the space
                    - if it has a snake/ladder, find that cell and assign to it instead
            - check the value of the n^2 square and return

            analysis:
            - time: O(n^2), where n=side length of the board
            - space: O(n^2) where n=side length of the board
        */
        int n = board.size();
        vector<int> minMoves(n*n+1, INT_MAX);
        deque<pair<int, int>> moves = {{1, 0}};
        while (!moves.empty()) {
            auto [val, steps] = moves.front();
            moves.pop_front();
            auto [row, col] = findCell(val, n);

            // climb up/slide down if we are on a snake/ladder
            if (board[row][col] != -1) {
                val = board[row][col];
                pair<int, int> jump = findCell(board[row][col], n);
                row = jump.first;
                col = jump.second;
            } 

            // don't continue if our current move is less efficient a previous one
            if (steps >= minMoves[val])
                continue;

            minMoves[val] = steps;
            for (int i=1; i<=min(6, n*n-val); i++) {
                moves.push_back({val+i, steps+1});
            }
        }
        return minMoves[n*n] == INT_MAX ? -1 : minMoves[n*n];
    }

    pair<int, int> findCell(int val, int n) {
        int row = n - 1 - (val-1)/n;
        int col = (n-row)&1 ? (val-1)%n : n - 1 - (val-1)%n;
        return {row, col};
    }
};