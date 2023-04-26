// 2023-04-26 (tabulation dp)
class Solution {
public:
    int MODULO = 1000000007;
    int numWays(vector<string>& words, string target) {
        /*
        notes:
        - form target using the words given in the dictionary
        - target[i] = words[j][k]
            - after using words[j][k], cannot use any characters from index k and before
        - seems like we just count the number of chars within each position and do some math?
        - we can count occurrences of each letter at each position, and do a sort of flow forward
          approach
            - list numbers length targetlength+1, initialized to 0
            - for each position, iterate from end to start of list, check if any chars match
              the char at that position, and carry previous values forward *= cur char count
            - return the end of the list at the end

        analysis:
        - time = O(m*n + m*t) where m=length of words[0], n=length of words, and t=length of target
        - space = O(m*n)
        */
        int m=words[0].length(), n = target.length();

        // ways[i] = number of ways to create target[0:i]
        vector<int> ways(n+1, 0);
        ways[0] = 1;
        
        for (int i=0; i<m; i++) { 
            unordered_map<char, int> charCounts;
            for (string& word : words) {
                charCounts[word[i]]++;
            }
            
            for (int j=n; j>0; j--) {
                ways[j] = (ways[j] + (1LL*ways[j-1]*charCounts[target[j-1]])) % MODULO;
            }
        }
        
        return ways[n];
    }
};