// 2022-05-26
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curLowest = prices[0];
        int curMax = 0;
        for (int p : prices) {
            if (p < curLowest) 
                curLowest = p;
            
            curMax = max(curMax, p - curLowest);
        }
        return curMax;
    }
};