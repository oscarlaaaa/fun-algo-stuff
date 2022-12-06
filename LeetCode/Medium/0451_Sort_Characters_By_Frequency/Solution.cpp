// 2022-12-02 (bucket sort)
class Solution {
public:
    string frequencySort(string s) {
        /*
            input: string s
            output: the string in decreasing order based on the frequency of the characters

            approach:
            - count frequencies using an array count to increment based on ascii values
            - push the character into the vector freq at the idx count[i]
            - iterate backwards from the freq and append on the character i times
        */
        // freq count of each character
        int counts[256] = {0};
        for (char &c : s) {
            counts[c]++;
        }
        
        // bucket sort the characters
        vector<vector<char>> freqs(s.length()+1, vector<char>());
        for (int i=0; i<256; i++) {
            if (!counts[i]) 
                continue;
            freqs[counts[i]].push_back(char(i));
        }

        // craft the output
        string output = "";
        for (int i=s.length(); i>=1; i--) {
            for (char &c : freqs[i]) {
                for (int j=0; j<i; j++) {
                    output += c;
                }
            }
        }
        return output;
    }
};