// 2023-01-30 (2d dp)
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        /*
            input: scores, and ages
            output: return the highest overall score of all possible teams

            notes:
            - want to avoid conflicts (i.e. a younger player has a higher 
              score than an older player)
            - basically, select as high of a score as possible without causing
              any conflicts
            - seems like we want to prioritize the highest scores possible even
              if they cause conflicts, until not causing a conflict will give more
              benefit
            - what if we sort it in order of age, and iterate through from lowest to
              highest to how much it'd "cost" to take an older player?
                - if the player costs more than they're worth, then they're not worth
                - iterate left to right, kind of like a cumsum that only accumulates
                  if the next value is >= (since ties are ok)? or maybe we can even sum
                  up the ages to make it simpler
                - doesn't really work as we run into issues with one player working with
                  everyone and our total sum being the entire thing, despite other conflicts
            - maybe even a double for loop to simplify things
            - maybe this is DP?

            approach:
            - create a vector of ints titled "totals"
            - group scores/ages together and sort it by ages in ascending order
            - iterate through using 2 for loops, i and j
                - if player[i] is younger and greater than player[j], then ignore
                - otherwise, see if adding totals[i] to player[j] would be greater than whatever
                  is currently stored at totals[j] 
            - basically "bubbling up" the scores based on age, and storing the best possible
              value at each position to see if taking a player would be better than taking a 
              previous player (and saving it if so)
            - return the max value within totals

            analysis:
            - time = O(n^2) where n = number of players
            - space = O(n) where n = number of players
        */
        int n = scores.size();
        vector<pair<int, int>> players;
        for (int i=0; i<n; i++) {
            players.push_back({ages[i], scores[i]});
        }
        sort(players.begin(), players.end());

        vector<int> totals(n);
        for (int i=0; i<n; i++) {
            totals[i] = players[i].second;
        }

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                auto& [age1, score1] = players[i];
                auto& [age2, score2] = players[j];
                
                // if there is a conflict, dont try to propogate the score forwards
                if (age1 < age2 && score1 > score2) 
                    continue;
                // otherwise, see if taking player i is better than whatever is already
                // stored at player[j]'s total
                totals[j] = max(totals[j], totals[i]+score2);
            }
        }
        return *max_element(totals.begin(), totals.end());
    }
};