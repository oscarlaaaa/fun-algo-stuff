// 2022-09-11 (sort -> 2 pointer)

// initial power - int
// initial score = 0
// tokens; token[i] = value of ith token

// can either:
//  - lose token[i] power and gain 1 score
//  - gain token[i] power and lose 1 score

// can play each token once and in any order
// don't have to play all the tokens

// approach:
// 1. sort the list of tokens from lowest to greatest
// 2. play cheap tokens face up until you run out of power
// 3. play an expensive token face down to regain power
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end(), [](const int& a, const int& b) {
            return a < b;
        });
        
        int totalScore = 0, greatestScore = 0;
        int remainingPower = power;
        int left = 0, right = tokens.size()-1;
        
        while (left <= right) {
            // play the cheapest token face up to gain score
            if (tokens[left] <= remainingPower) {
                remainingPower -= tokens[left];
                left++;
                totalScore++;
            // play the most expensive token face down to gain power
            } else if (tokens[left] > remainingPower && totalScore > 0) {
                remainingPower += tokens[right];
                right--;
                totalScore--;
            // unable to play face down as we have a score of 0
            } else {
                break;
            }
            
            greatestScore = max(greatestScore, totalScore);
        }
        
        return greatestScore;
    }
};