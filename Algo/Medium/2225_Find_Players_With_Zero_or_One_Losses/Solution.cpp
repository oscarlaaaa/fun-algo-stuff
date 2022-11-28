// 2022-11-27
/*
    input: 2d int vector matches, where match[0] = winner and match[1] = loser
    output: 2d int vector answer, where answer[0] = undefeated and answer[1] = only lost once

    notes:
    - return in increasing order
    - only consider players who have played at least 1 match
    - no 2 matches have the same outcome
    - only need to care about losses + have played before

    approach:
    - sorted map of players, and num of losses
    - iterate through to iterate each player's num of losses
    - construct output at the end
*/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        map<int, int> losses;
        for (vector<int> match : matches) {
            int winner = match[0], loser = match[1];
            if (!losses.count(winner)) losses[winner] = 0;
            if (!losses.count(loser)) losses[loser] = 0;
            losses[loser]++;
        }

        vector<vector<int>> output(2);
        for (auto itr=losses.begin(); itr != losses.end(); ++itr) {
            auto [player, lossCount] = *itr;
            if (lossCount <= 1) {
                output[lossCount].push_back(player);
            } 
        }
        
        return output;
    }
};