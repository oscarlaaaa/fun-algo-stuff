// 2022-11-18 (meth)
class Solution {
public:
    bool isUgly(int n) {
        /*
        reasoning: if a number is divisible by another number, it should be able
        to be reduced down to 1 after dividing it many times over. however, given that
        prime numbers are prime (only factor is itself and 1), numbers that are not divisible
        by 2, 3, or 5 all the way down indicate that it has another larger prime it is divisible 
        by since all numbers between prime numbers are divisible by at least one prime before it.
        */
        if (n <= 0) return false;
        while (n%2 == 0) n /= 2;
        while (n%3 == 0) n /= 3;
        while (n%5 == 0) n /= 5;
        return n == 1;
    }
};