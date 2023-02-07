// 2023-02-07 (sliding window kinda)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        /*
            input: a string s, and a string p to find anagrams of
            output: start indices of every anagram of p within s

            notes:
            - sliding window to find anagrams most likely
            - utilize a map to keep track of character count of p, as well as
              windows of s
                - honestly vectors might be faster
            - equate the maps to find all anagrams
            - could even just have a fixed size window that slides down, since
              the size has to be == to the size of p to be an anagram
            
            analysis:
            - time = O(n) where n=length of s
            - space = O(1)
        */
        int n = s.size(), m = p.size();
        vector<int> windowCount(26), needed(26);
        for (char c : p)
            needed[c-'a']++;
        
        vector<int> anagramStarts;
        for (int i=0; i<n; i++) {
            windowCount[s[i]-'a']++;
            if (i >= m) {
                windowCount[s[i-m]-'a']--;
            }
            if (windowCount == needed)
                anagramStarts.push_back(i-m+1);
        }
        return anagramStarts;
    }
};