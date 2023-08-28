// 2023-08-26 (dp)
class Solution {
public:
    bool canCross(vector<int>& stones) {
        /*  
        notes:
        - frog can only jump k +-= 1 and only forward
        - seems like there are multiple paths we can take:
            - jumping too fast forward means we may have some areas where we jump too far
            - jumping too little means we may not jump far enough at some places
        - maybe apply all possible jumps forward and add it to a set of possible jumps?
            - kinda weird DP?
            - we can use a map to ensure that we save space + only check what's necessary
                - can add in all of our stone positions so that only those positions are valid
                - can check if jump reaches a certain position by setting these positions at the start
        
        analysis:
        - time = O(n^2)
        - space = O(n^2)
        */
        int n = stones.size();
        unordered_map<int, unordered_set<int>> possibleJumps;

        if (stones[1] != 1)
            return false;
        
        for (int stone : stones) {
            possibleJumps[stone] = unordered_set<int>();
        }

        possibleJumps[0].insert(1);

        for (int stone : stones) {
            for (int jumpDist : possibleJumps[stone]) {
                if (!possibleJumps.count(stone+jumpDist))
                    continue;

                if (jumpDist-1 > 0) 
                    possibleJumps[stone+jumpDist].insert(jumpDist-1);
                
                possibleJumps[stone+jumpDist].insert(jumpDist);
                possibleJumps[stone+jumpDist].insert(jumpDist+1);
            }
        }

        return possibleJumps[stones.back()].size() > 0;
    }
};