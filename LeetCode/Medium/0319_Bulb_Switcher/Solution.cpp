// 2023-04-27 (lol)
class Solution {
public:
    int bulbSwitch(int n) {
        /*
        notes:
        - n bulbs that are initially off
        - from i = 1 to n, toggle every ith bulb
        - return the number of bulbs on after n rounds
        - definitely looks like a raw math question given that n can be 1e9
        
        1: 1
        4: 2
        9: 3
        16: 4

        o x x o x x x x o x x x x x x o

        basically the floor of the square root of each number

        analysis:
        - time = O(1)
        - space = O(1)
        */
        return floor(sqrt(n));
    }
};