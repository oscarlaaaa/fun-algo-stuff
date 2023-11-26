// 2023-11-26
class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        /*
        notes:
        - we need to find a way to easily match what substrings match each other
            - one way is tracking v-c or vice-versa cumulatively, and finding another
              point down the way with the same v-c difference
                - ex. if we have -2 at position 3 (v1c3 is 1-3), then we just need to find a further
                  point that is also -2 (v2c4 is 2-4) since v=2-1=1 and c=4-3=1 which makes them equal
        - can utilize two-sum approach with hashing to find matching differences without backtracking
        - we can store the position of each difference (i) we encounter within a map, and find the # of
          vowels/consonants of each substring from [i, j] by doing (j-i)/2 since vowels == consonants
        - weird how we return a long long since i don't think we exceed int upper bound but yolo

        analysis:
        - time = O(n^2)
        - space = O(n^2)
        */
        int n = s.length();
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        vector<int> counts(n+1);
        
        int v = 0, c = 0;
        for (int i=0; i<n; i++) {
            if (vowels.count(s[i])) {
                v++;
            } else {
                c++;
            }
            counts[i+1] = c-v;
        }
        
        int substrings = 0;
        unordered_map<int, vector<int>> diffs;
        for (int i=0; i<=n; i++) {
            for (int val : diffs[counts[i]]) {
                int vowelConsonants = (i - val)/2;

                if ((vowelConsonants*vowelConsonants)%k == 0) {
                    substrings++;
                }
            }
            diffs[counts[i]].push_back(i);
        }
        
        return substrings;
    }
};