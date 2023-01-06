// 2023-01-05 (sorting)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        /*
            input: list of int costs, and int coins
            output: the greatest number of ice cream bars u can buy

            note:
            - sort and iterate?? is it that simple?
        */
        sort(costs.begin(), costs.end());
        int bars = 0;
        for (int cost : costs) {
            if (cost > coins)
                break;
            coins -= cost;
            bars++;
        }
        return bars;
    }
};