// 2023-12-21 (cumsum)
class Solution {
public:
    int maxScore(string s) {
        /*
        notes:
        - want to maximize # zeroes on left + # zeroes on right
        - just need to cumsum zeroes from left + ones from right
        - 2 cumsum arrays, where array[i] means splitting the string between
          i-1 and i
        
        analysis:
        - time = O(n)
        - space = O(n)
        */
        int n = s.length();
        std::vector<int> zeroes(n+1), ones(n+1);
        for (int i=0; i<n; i++) {
            // count zeroes from left
            zeroes[i+1] = zeroes[i];
            ones[n-1-i] = ones[n-i];
            if (s[i] == '0') {
                zeroes[i+1]++;
            } 
            // count ones from right
            if (s[n-1-i] == '1') {
                ones[n-1-i] = ones[n-i]+1;
            }
        }
        // we only look at splits from [1, n-1] as zeroes[i] and ones[i] represents
        // a split between i-1 and i, and we want non-empty splits
        int maximum = 0;
        for (int i=1; i<n; i++) {
            maximum = std::max(maximum, zeroes[i]+ones[i]);
        }
        return maximum;
    }
};