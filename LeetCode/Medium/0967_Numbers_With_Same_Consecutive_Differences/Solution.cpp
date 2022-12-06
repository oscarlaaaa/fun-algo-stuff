// 2022-09-05
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> output;
        for (int i=1; i<10; i++) {
            generateSameConsecDiffNums(output, n-1, k, i);
        }
        return output;
    }
    
    void generateSameConsecDiffNums(vector<int>& output, int digitsRemaining, int diff, int curNum) {
        if (digitsRemaining == 0) {
            output.push_back(curNum);
            return;
        }
        
        int prevDigit = curNum % 10;
        
        if (prevDigit + diff <= 9)
            generateSameConsecDiffNums(output, digitsRemaining-1, diff, (curNum*10 + prevDigit+diff));
        
        // prevent adding the same number twice if diff is 0
        if (diff != 0 && prevDigit - diff >= 0)
            generateSameConsecDiffNums(output, digitsRemaining-1, diff, (curNum*10 + prevDigit-diff));
    }
};