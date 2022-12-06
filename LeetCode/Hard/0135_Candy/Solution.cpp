// 2022-07-04 (two-pass greedy method)
/*
 * This question can be solved by thinking about the ratings strictly as
 * 'how many consecutive children am i greater than'. If you look at an array
 * [10, 5, 1, 2, 3], both the 10 and the 3 rating children would have the same
 * amount of candy with an output of [3, 2, 1, 2, 3] because it's not the actual rating
 * for each child that matters but instead whether its rating is greater than its
 * neighbour. As such, we can simply traverse the ratings from both directions,
 * and if a neighbour has a higher rating but lower/equal candies, we can simply put it
 * at 1 higher than the current.
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1); // initialize everyone at 1 candy
        for (int i=0; i<candies.size()-1; i++) {
            if (ratings[i] < ratings[i+1] && candies[i] >= candies[i+1]) 
                candies[i+1] = candies[i]+1;
        }
        for (int i=candies.size()-1; i>=1; i--) {
            if (ratings[i] < ratings[i-1] && candies[i] >= candies[i-1])
                candies[i-1] = candies[i]+1;
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
