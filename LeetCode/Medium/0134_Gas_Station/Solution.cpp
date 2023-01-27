// 2022-05-26
/**
 * Greedy approach: you can assume that if you are traveling and run
 * out of fuel, then the start position wouldn't be behind you since
 * not running out before the current position means that:
 *   - you didn't start on a negative position
 *   - moving your start position forward will only remove gains in gas
 * 
 * Thus, we can go for 2 rounds and if we run out of fuel, just pick up
 * where we left off.
 * 
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, hits = 0;
        // limit if size*2 so if we can still loop if we start at the end
        for (int i = 0; i < gas.size()*2; i++) {
            int idx = i % gas.size();
            totalGas += gas[idx] - cost[idx];

            if (totalGas < 0) {
                totalGas = hits = 0;
            } else {
                hits++;
                if (hits == gas.size()) 
                    return idx+1 == gas.size() ? 0 : idx+1;
            }
        }
        return -1;
    }
};

// 2023-01-06 (greedy)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
            input: list of gas stations, and list of costs to travel to the next station
            output: the starting gas station to travel around once

            notes:
            - probably need to iterate from 0 to 2n to account for possibly starting at end
            - greedy approach maybe? 
                - maybe start at 0th gas station, and iterate forwards until either its not
                  possible to get to the next one, or if starting at that station will yield
                  you more gas than you'd have at that moment
            - maybe keeping track of remaining gas, and replacing your remaining gas + starting
              point whenever you run out
        */
        int n = gas.size();
        int start = 0, remainingGas = 0;
        for (int i=0; i<2*n; i++) {
            int idx = i%n;
            if (remainingGas < 0) {
                remainingGas = 0;
                start = i;
            } else {
                if (i-start >= n)
                    return start;
            }
            remainingGas += gas[idx] - cost[idx];
        }
        return -1;
    }
};