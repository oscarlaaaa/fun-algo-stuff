// 2023-03-01 (brute force baybee)
class Solution {
public:
    // checks if we have enough characters available to take the word
    bool canUse(vector<int>& remaining, vector<int>& word) {
        bool canUse = true;
        for (int i=0; i<26 && canUse; i++) {
            if (word[i] > remaining[i]) {
                canUse = false;
            }
        }
        return canUse;
    }

    int findMaxScore(vector<int>& remaining, vector<vector<int>>& wordCounts, int pos, vector<int>& scores) {
        if (pos >= wordCounts.size())
            return 0;
        
        // skip current word
        int maxScore = findMaxScore(remaining, wordCounts, pos+1, scores);

        // take current word if possible
        if (canUse(remaining, wordCounts[pos])) {
            int score = 0;
            for (int i=0; i<26; i++) {
                if (wordCounts[pos][i] == 0)
                    continue;
                remaining[i] -= wordCounts[pos][i];
                score += scores[i]*wordCounts[pos][i];
            }
            score += findMaxScore(remaining, wordCounts, pos+1, scores);
            maxScore = max(maxScore, score);
            for (int i=0; i<26; i++) {
                remaining[i] += wordCounts[pos][i];
            }
        }
        return maxScore;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        /*
            input: a list of words, a list of single letters, and a list of scores of each letter
            output: max score of any valid set of words formed by the given letters

            notes:
            - probably need to track letter counts of each word and scores for each char
            - is this like the knapsack problem?
                - the num of words seems pretty low, so it's probably brute forcey
            
            approach:
            - generate char counts for every word, as well as our available letters
            - recursively explore combinations of words, and return highest score combo

            analysis:
            - time = O(2^n) where n=length of words
            - space = O(n) where n=length of words
        */
        vector<int> remaining(26);
        vector<vector<int>> wordCounts(words.size(), vector<int>(26));
        for (char letter : letters)
            remaining[letter-'a']++;
        for (int i=0; i<words.size(); i++) {
            for (char letter : words[i]) {
                wordCounts[i][letter-'a']++;
            }
        }

        return findMaxScore(remaining, wordCounts, 0, score);
    }
};