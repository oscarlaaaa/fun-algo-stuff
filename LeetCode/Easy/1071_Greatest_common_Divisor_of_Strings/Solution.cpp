// 2023-01-31 (Euclidean algorithm)
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        /*
            input: two strings
            output: the largest strting that divides both strings

            notes:
            - basically finding the largest repeating pattern from both strings?
            - take the smallest string, and iterate until you hit a non-unique char
              to find the largest non-repeating? plus if you hit unique chars then
              the pattern cannot be repeating anyways
            
            approach:
            - iterate over both strings, until one hits the end
                - if a character doesn't match, return ""
            - once one string hits the end, we know that they have a common denominator
              and can continue finding it
            - utilize a recursive function that repeatedly subtracts the length of the
              smaller one from the larger one, and recurses until the smaller one has a length of 0
            - eventually, we'll be left over with the greatest common divisor (i dont really know why)
        */  
        int m = str1.length(), n = str2.length();
        for (int i=0; i<max(m, n); i++) {
            if (str1[i%m] != str2[i%n])
                return "";
        }
        return findGCD(str1, str2);
    }

    string findGCD(string s1, string s2) {
        if (s1.length() < s2.length())
            return findGCD(s2, s1);
        
        if (s2.length() == 0)
            return s1;

        return findGCD(s1.substr((int) s2.length()), s2);
    }
};