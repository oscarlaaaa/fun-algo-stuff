// 2023-01-26 (memoized DFS with bucket groupings)
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        /*
            input: a list of strings
            output: all concatenated words in a given list of words

            notes:
            - concatenated word = string comprised of 2+ shorter words in the array
            - 10^4 possible words?? holy
                - probably have to be like O(nlogn) or O(n) algo? (would n^2 be possible?)
            - maybe for each shorter word, check if the longer ones match the shorter one
                - could probably reduce problem size by incrementally cutting down like that
                - issue is like if we have "cat" and "cats" with "catsdogcats", then its a lil diff
            - maybe buckets of what each word starts with?
                - this way, we only have to compare words that could possibly match
                - maybe use pairs to maintain reference to original word
            - queue to see what letter groups we should re-iterate over?

            approach:
            - initialize buckets to hold what each word starts with (vector or map)
                - initialize second group of buckets to hold broken-down words
            - queue with our words that we want to process, + reference to the original word
            - process items in the queue
                - if we've already added the original word to our output, then skip over it
                - loop over our original words that start with the same letter
                - skip if queue word is smaller than the original, or if the original word matches the queue 
                  word's original
                - check if the beginning of the words match
                    - if the remainder of the word is in our "isConcat" set, then it is a concatenated word and
                      we can:
                        - add the original word to our "seen" set to prevent re-processing
                        - add the remaining word to our "isConcat" set as it is concatable
                        - add the original word to our output
                    - otherwise, just push the leftover back into our queue
        */
        unordered_set<string> isConcat;   // holds strings that are confirmed as a concatable string
        vector<vector<string>> originalWords(26); // holds our original words within buckets
        deque<pair<string, int>> remainingWords;   // queue of <remainingWord, originalWord index>

        // queue up our words, place originals into buckets, and set up our "isConcat" checker
        for (int i=0; i<words.size(); i++) {
            originalWords[words[i][0]-'a'].push_back(words[i]);
            remainingWords.push_back({words[i], i});
            isConcat.insert(words[i]);
        }

        unordered_set<string> seen;
        vector<string> concatenated;
        while (!remainingWords.empty()) {
            auto [remain, originalIndex] = remainingWords.back();
            remainingWords.pop_back();

            // prevent processing words we've already added to our output
            if (seen.count(words[originalIndex]))
                continue;

            // loop through words starting with the same letter as the remainder
            for (string& w : originalWords[remain[0]-'a']) {
                // don't process if remainder is smaller than the word, or if the word matches the original
                if (remain.length() < w.length() || w == words[originalIndex])
                    continue;
                
                // if our original word matches the beginning of our remainder
                if (w == remain.substr(0, w.length())) {
                    string next = remain.substr(w.length());
                    
                    // if we've broken down the entire string, or if the current string leads to a fully broken down
                    // string, then we want to do the following:
                    if (isConcat.count(next)) {
                        isConcat.insert(remain);    // mark remaining string as leading to a concatenated string
                        seen.insert(words[originalIndex]);      // mark original string to prevent re-processing
                        concatenated.push_back(words[originalIndex]); // add to output
                        break;                      // break to prevent accidently re-adding in the same loop
                    } else {
                        remainingWords.push_back({next, originalIndex});
                    }
                }
            }
        }
        return concatenated;
    }
};

// 2023-01-27 (tabulated DP)
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        /*
            input: a list of strings
            output: all concatenated words in a given list of words

            approach:
            - shove all original words within a set
            - iterate through the list of words
                - initialize a tabulative DP list, where dp[i] means there it is possible to
                  un-concatenate a word to create a string starting at index i from the original
                - use a double for loop to check every single possible substring if it matches
                  with any original word
                - mark the areas that are reachable, and skip if the left bound is ever not reachable
            - if a word has its dp list at index word.length() reachable, that means that
              its possible to concat original words to form that word, and we can add it to our
              output list
        */
        unordered_set<string> originalWords(words.begin(), words.end());
        vector<string> concatenated;
        for (string& word : words) {
            int n = word.length();
            vector<bool> dp(n+1);
            dp[0] = true;

            for (int i=0; i<n; i++) {
                if (!dp[i])
                    continue;

                for (int j=i+1; j<=n; j++) {
                    // prevent a word from matching with itself
                    if (i == 0 && j == n)
                        continue;

                    if (originalWords.count(word.substr(i, j-i))) {
                        dp[j] = true;
                    }
                }
            }

            if (dp[n])
                concatenated.push_back(word);
        }
        return concatenated;
    }
};