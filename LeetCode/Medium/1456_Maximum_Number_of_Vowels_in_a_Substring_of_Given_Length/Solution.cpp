// 2023-05-08 (sliding window)
class Solution {
public:
    int maxVowels(string s, int k) {
        /*
        notes:
        - looks like it's just a sliding window, except with a fixed size k
        - probably just count up the number of vowels, and add/subtract whenever
          we shift forwards
        - substring = continuous, so is this really that simple?

        analysis:
        - time = O(n) where n=length of s
        - space = O(1)
        */
        int n = s.length();
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        int vowelCount = 0, maxVowelCount = 0;
        for (int i=0; i<n; i++) {
            if (vowels.count(s[i]))
                vowelCount++;

            if (i >= k && vowels.count(s[i-k]))
                vowelCount--;
            
            maxVowelCount = std::max(vowelCount, maxVowelCount);
        }
        return maxVowelCount;
    }
};