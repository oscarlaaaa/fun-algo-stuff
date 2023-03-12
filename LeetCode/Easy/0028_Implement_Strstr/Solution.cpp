// 2023-03-11
class Solution {
public:
    int strStr(string haystack, string needle) {
        /*
        input: string haystack and string needle to find in haystack
        output: index of needle in haystack

        notes:
        - simply iterate through and substring portions of haystack to 
          compare with needle
        
        analysis:
        - time = O(m*n) where m=length of haystack and n=length of needle
        - space = O(1)
        */
        int m = haystack.length(), n = needle.length();
        for (int i=0; i+n <= m; i++) {
            if (haystack.substr(i, n) == needle)
                return i;
        }
        return -1;
    }
};