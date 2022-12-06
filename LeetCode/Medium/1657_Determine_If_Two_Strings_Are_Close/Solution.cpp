// 2022-12-01
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        /*
            input: 2 strings
            output: whether the words are considered "close"

            notes:
            - allowed operations
                - swap the value of every occurrence of one char with another
                - swap any 2 existing characters
            - swapping can give us any possible perm, so order doesn't matter
            - need to have same counts of char occurrences to be close
            - also need same chars

            approach:
            - arrays to hold character counts
            - count chars in word 1 and word2 in separate arrays
            - vector<int> of length of longest string
            - for each count value for word 1, increment vector[countval]
            - for each count value for word 2, decrement vector[countval]
                - check that both have the same characters while doing so
            - return true if count values are all 0
        */
        if (word1.length() != word2.length()) 
            return false;
        
        // count chars in words
        int count1[26] = {0}, count2[26] = {0};
        for (int i=0; i<word1.length(); i++) {
            count1[word1[i] - 'a']++;
            count2[word2[i] - 'a']++;
        }
        
        // count frequencies of chars in both (increment for word1, decrement for word2)
        vector<int> freqs(max(word1.size(), word2.size())+1, 0);
        for (int i=0; i<26; i++) {
            if (count1[i] == 0 && count2[i] != 0 || count1[i] != 0 && count2[i] == 0) 
                return false;
            freqs[count1[i]]++;
            freqs[count2[i]]--;
        }

        // all frequencies should be 0
        for (int i=0; i<freqs.size(); i++) {
            if (freqs[i] != 0) return false;
        }
        return true;
    }
};