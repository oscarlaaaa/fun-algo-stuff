class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /*
            input: 2 strings
            output: whether they are isomorphic

            notes:
            - isomorphic = all chars in s can be mapped to t without overlap
            - multiple s characters cannot map to the same t character
            - need to keep track of both ways:
              - need to check whether an s character has already been mapped
              - if not, need to check whether the character it'd map to is taken
        */
        int n = s.length();
        vector<char> stot(256), ttos(256);
        for (int i=0; i<n; i++) {
            if (stot[s[i]] && stot[s[i]] != t[i])
                return false;
            if (ttos[t[i]] && ttos[t[i]] != s[i])
                return false;
            ttos[t[i]] = s[i]; 
            stot[s[i]] = t[i]; 
        }
        return true;
    }
};