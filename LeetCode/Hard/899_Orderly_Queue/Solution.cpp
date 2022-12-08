// 2022-12-06 (big brain)
class Solution {
public:
    string orderlyQueue(string s, int k) {
        /*
            input: a string, and an integer k
            output: lexicographically samllest string after applying the moves

            abcdef k = 1

            notes:
            - k = number of starting chars you can move to the back of the string
            - if k == 1, you can only cycle through as a circular tring
            - if k == 2, can you make any permutation of letters possible? i think so
                because when k=2 effectively swaps adjacent characters
            - so as long as k >= 2, you just sort characters and return
        */
        if (k == 1) {
            string smallest = s;
            for (int i=1; i<s.length(); i++) {
                smallest = min(smallest, s.substr(i) + s.substr(0, i));
            }
            return smallest;
        }

        int counts[256] = {0};
        for (char& c : s) {
            counts[c]++;
        }

        string output = "";
        for (int i=0; i<256; i++) {
            output.append(counts[i], char(i));
        }
        return output;
    }
};