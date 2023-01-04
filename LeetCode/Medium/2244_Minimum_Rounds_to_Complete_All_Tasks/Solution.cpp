// 2022-01-04
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        /*
            input: list of int task difficulty levels
            output: minimum rounds required to complete all tasks

            notes:
            - can either complete 2 or 3 tasks of the same difficulty level
            - looks like we can just count difficulty levels
            - we fail if a difficulty only has 1; otherwise, we can always clear it
            - optimal would be to mod 3 and see the result:
                - 0 = we've cleared, so rounds = num/3
                - 1 = we can replace a 3 with two 2s, so rounds = ceil(num/3)
                - 2 = we can use a 2 to finish it up, so rounds = ceil(num/3)
            
            approach:
            - count num of tasks for each difficulty
            - keep track of total rounds
            - iterate through our count and see:
              - if it's 1, then we return -1 as it cannot be cleared
              - otherwise, total rounds += ceil(num/3)
            - return count
        */
        unordered_map<int, int> diffCount;
        for (int task : tasks) {
            diffCount[task] += 1;
        }

        int rounds = 0;
        for (auto [_, count] : diffCount) {
            if (count == 1) 
                return -1;
            rounds += (int) ceil(1.0*count / 3);
        }
        return rounds;
    }
};