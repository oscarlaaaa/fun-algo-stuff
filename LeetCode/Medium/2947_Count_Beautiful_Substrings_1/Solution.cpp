// 2023-11-25 (brute)
class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        unordered_map<int, int> counts;
        
        for (int i=0; i<n; i++) {
            int v = 0, c = 0;
            for (int j=i; j<n; j++) {
                if (vowels.count(s[j])) {
                    v++;
                } else {
                    c++;
                }
                if (v == c) {
                    counts[v]++;
                }
            }
        }
        
        int substrings = 0;
        for (auto [a, v] : counts) {
            if ((a*a)%k == 0) {
                substrings += v;
            }
        }
        return substrings;
    }
};