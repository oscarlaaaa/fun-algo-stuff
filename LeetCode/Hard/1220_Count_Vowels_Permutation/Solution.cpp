// 2023-10-28
class Solution {
public:
    int countVowelPermutation(int n) {
        /*
        notes:
        - count the # of strings that can be formed with the vowel rules
            - e after a
            - a or i after e
            - i cannot come after i
            - i or u after u
            - a after u
        - basically, what can come after each char:
            - a: [e]
            - e: [a, i]
            - i: [a, e, o, u]
            - o: [i, u]
            - u: [a]
        - need to find all possibilities that can come from n vowels
            - can't we just build it going forward like DP?
            - actually, don't we only need to track how many string end in each vowel?
                - track using a hashmap, and probably modulo each time?
                - each iteration, convert a into e, e into a and i, etc.
                - modulo each step
        
        analysis:
        - time = O(n)
        - space = O(1)
        */
        const int MOD = 1000000007;
        int vowelCounts[5] = {1,1,1,1,1};
        vector<vector<int>> next = {
            {1},
            {0,2},
            {0,1,3,4},
            {2,4},
            {0}
        };

        for (int i=1; i<n; i++) {
            int nextVowels[5] = {0,0,0,0,0};

            for (int vowel=0; vowel<5; vowel++) {
                for (int nextVowel : next[vowel]) {
                    nextVowels[nextVowel] = (0LL + nextVowels[nextVowel] + vowelCounts[vowel])%MOD;
                }
            }
            copy(nextVowels, nextVowels+5, vowelCounts);
        }

        int total = 0;
        for (int vowelCount : vowelCounts) {
            total = (0LL + total + vowelCount)%MOD;
        }
        return total;
    }
};