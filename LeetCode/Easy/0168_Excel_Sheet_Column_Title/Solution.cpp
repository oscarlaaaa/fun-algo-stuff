// 2023-08-21
class Solution {
public:
    string convertToTitle(int columnNumber) {
        /*
        notes:
        - given an integer, return its corresponding column title
        - can basically think of it as base 26 with 0 to 25 being A to Z
            - can you just subtract 1 from the column number? probably
        - basically just subtract 1 from columnNumber, and keep running % 26 to get the
          corresponding letter and repeating on the remainder

        analysis:
        - time = O(1) since int has a ceiling of 2^31-1
        - space = O(n) for construction the solution
        */
        int BASE = 26;

        // we need to subtract 1 every iteration to account for the index shift
        int remaining = columnNumber-1; 

        string output = "";
        do {
            char column = 'A' + remaining%BASE;
            output = column + output;
            remaining = remaining/BASE - 1;
        } while (remaining >= 0);

        return output;
    }
};