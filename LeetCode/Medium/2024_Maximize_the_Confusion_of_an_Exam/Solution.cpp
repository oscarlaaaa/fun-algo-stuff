// 2023-07-07 (sliding window)
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        /*
        notes:
        - able to flip K answers in the answer key
        - want to maximize the number of consecutive T or F
        - probably sliding window? and shrinking whenever the lowest count
          of T/F exceeds K
        - return the longest possible window size

        analysis:
        - time = O(n) where n=length of answerKey
        - space = O(1)
        */
        int n = answerKey.length(), longest = 1;
        int t = 0, f = 0;
        int start = 0;
        for (int end = 0; end < n; end++) {
            if (answerKey[end] == 'T') {
                t++;
            } else {
                f++;
            }

            while (std::min(t, f) > k) {
                if (answerKey[start] == 'T') {
                    t--;
                } else {
                    f--;
                }
                start++;
            }

            longest = std::max(longest, end-start+1);
        }
        return longest;
    }
};