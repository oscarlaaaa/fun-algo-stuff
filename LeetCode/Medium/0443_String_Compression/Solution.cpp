// 2023-03-01 (stack-ish? idk)
class Solution {
public:
    void printarr(vector<char>& chars) {
        cout << "[";
        for (char c : chars)
            cout << c << ",";
        cout << "]" << endl;
    }
    int compress(vector<char>& chars) {
        /*
            input: a list of characters
            output: the length of the compressed list

            compression algo
            - if the group length is 1, append the char to s
            - else, append the char followed by the group length

            notes:
            - we have to do it in place, so we need to represent
              the char count using numeric digits
                - probably handle using division and modulo?
            - maybe one pointer to mark where we're inserting, and another
              for the actual progress
                - can pop off the useless stuff after we're done OR just mark the
                  chars using periods and swap them to the end afterwards
        */
        chars.push_back('\0');
        int n = chars.size();
        int cur = 0, count = 0;
        for (int i=0; i<n; i++) {
            if (chars[i] == chars[cur]) {
                count++;
                if (count > 1)
                    chars[i] = '\0'; // mark should-be empty spaces with null character
            } else {
                if (count > 1) {
                    cur++;
                    deque<int> digits;
                    while (count > 0) {
                        digits.push_back(count%10);
                        count /= 10;
                    }
                    while (!digits.empty()) {
                        chars[cur] = digits.back() + '0';
                        digits.pop_back();
                        cur++;
                    }
                }
                cur = i;
                count = 1;
            }
        }    

        int left = 0, right = left;
        while (left < n && right < n) {
            if (chars[left] == '\0' && chars[right] != '\0')
                swap(chars[left], chars[right]);
            if (chars[left] != '\0') {
                left++;
                right++;
            } else if (chars[right] == '\0') {
                right++;
            }
        }

        return left;
    }
};