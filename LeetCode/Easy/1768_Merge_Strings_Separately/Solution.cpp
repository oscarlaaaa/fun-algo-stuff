// 2023-04-17
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        /*
        complexity:
        - time = O(n+m) where n=word1.length and m=word2.length
        - space = O(n+m) if we include output string, else O(1)
        */
        string output = "";
        int m = word1.length(), n = word2.length();
        int i = 0, j = 0;
        while (i < m && j < n)
            output = output + word1[i++] + word2[j++];
        if (i < m)
            output += word1.substr(i);
        if (j < n)
            output += word2.substr(i);
        return output;
    }
};