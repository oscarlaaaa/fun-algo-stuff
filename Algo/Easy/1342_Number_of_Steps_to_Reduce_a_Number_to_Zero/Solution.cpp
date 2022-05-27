// 2022-05-26
class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num > 0) {
            if (num%2 == 0) 
                num = num >> 1;
            else
                num -= 1;
            count++;
        }
        return count;
    }
};