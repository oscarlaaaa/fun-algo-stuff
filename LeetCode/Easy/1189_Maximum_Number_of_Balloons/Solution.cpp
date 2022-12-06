// 2022-12-02
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count[26] = {0};
        for (char &c : text)
            count[c - 'a']++;
        
        int lowest = text.length();
        string balloon = "balloon";
        for (char c : balloon) {
            if (c == 'l' || c == 'o') {
                lowest = min(lowest, count[c - 'a']/2);
            } else {
                lowest = min(lowest, count[c - 'a']);
            }
        }
        return lowest;
    }
};