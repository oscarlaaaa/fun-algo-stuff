// 2022-11-22 (dp tabulation)
class Solution {
public:
    int numSquares(int n) {
        /*
        input: n number to break down into perfect squares
        output: number of perfect squares that sum to n

        notes:
        - greedy approach of subtracting greatest square doesn't work (ex. 12)
        - 1 4 9 16 25 36 49 64 81 100 121 144

        approach:
        - generate list of squares
        - initialize int vector of size n+1 (initialized with INT_MAX)
            - represents how many perfect squares to reach that number (represented by the idx)
        - DP tabulation and return n
            - for each index, check if current value + 1 < currentidx+square value, and replace it if so
              for every square in our squares list
        */
        
        vector<int> numSquare(n+1, INT_MAX), squares=generateSquares((int)sqrt(n));
        numSquare[0] = 0;
        for (int i=0; i<=n; i++) {
            for (int square : squares) {
                if (i+square > n) continue;
                numSquare[i+square] = min(numSquare[i]+1, numSquare[i+square]);
            }
        }
        return numSquare[n];
    }

    vector<int> generateSquares(int n) {
        vector<int> output;
        for (int i=n; i>=1; i--) {
            output.push_back(i*i);
        }
        return output;
    }
};