// 2023-05-01
class Solution {
public:
    double average(vector<int>& salary) {
        /*
        notes:
        - find the minimum and maximum values
        - subtract from the sum
        - return the sum / count-2

        analysis:
        - time = O(n) where n=length of salary
        - space = O(1)
        */
        int lowest = INT_MAX, highest = INT_MIN, total = 0;
        for (int num : salary) {
            lowest = min(lowest, num);
            highest = max(highest, num);
            total += num;
        }
        return 1.0*(total - lowest - highest) / (salary.size()-2);
    }
};