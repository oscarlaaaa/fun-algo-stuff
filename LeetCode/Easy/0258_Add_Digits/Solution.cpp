// 2023-04-26 (with loop)
class Solution {
public:
    int addDigits(int num) {
        /*
        analysis:
        - time = O(n)
        - space = O(1)
        */
        int total = 0;
        while (num > 0) {
            int val = num;
            total += num%10;
            total = total/10 + total%10;
            num /= 10;
        }
        return total;
    }
};

// 2023-04-26 (holy moly)
class Solution {
public:
    int addDigits(int num) {
        /*
        analysis:
        - time = O(1)0
        - space = O(1)
        */
        if (num == 0) return 0;
        return (num%9 == 0 ? 9 : num%9);
    }
};