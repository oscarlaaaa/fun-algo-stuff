// 2023-03-31 (memoization)
class Solution {
public:
    unordered_map<string, unordered_map<string, bool>> memo;
    bool isScramble(string s1, string s2) {
        /*
        notes:
        - we can:
            - split the string into 2 non-empty substrings
            - decide to swap the substrings or keep in the same order
            - repeat on each substring
        - determinant of whether it's possible is if a substring portion of s1
          has the same characters as either side of s2
            - can use that to determine whether it's possible or not
        - recursively process substrings?
            - greedily iterate on either end until we find as many matches as possible,
              then re-process with substrings
        - 2 cases where we know we want to split and process:
            - if our character counts for the left side of s1 and the left OR right side 
              of s2 match AND
                - if the current indices for s1 and s2 don't match
                - if we've had a perfect match so far but will break our perfect match on 
                  the next iteration
        
        analysis:
        - time = O(n^4)?
        - space = O(n^3)?
        */
        if (s1.length() == 1)
            return s1[0] == s2[0];

        if (this->memo.count(s1) && this->memo[s1].count(s2))
            return this->memo[s1][s2];
        if (this->memo.count(s2) && this->memo[s1].count(s1))
            return this->memo[s2][s1];

        int n = s1.length();
        vector<int> s1charCount(26), s2charCount1(26), s2charCount2(26);
        bool leftRightMatch = true, rightLeftMatch = true;
        for (int i=0, j=n-1; i<n; i++, j--) {
            s1charCount[s1[i]-'a']++;  // tracks chars left to right from s1
            s2charCount1[s2[i]-'a']++; // tracks chars left to right from s2
            s2charCount2[s2[j]-'a']++; // tracks chras right to left from s2

            // tracks whether we have a current perfect match in progress
            leftRightMatch = leftRightMatch && s1[i] == s2[i];
            rightLeftMatch = rightLeftMatch && s1[i] == s2[j];

            // stop if we've already added the last char as we can't process empty strings
            if (i == n-1) 
                continue;
            
            if (s1charCount == s2charCount1 && (s1[i] != s2[i] || leftRightMatch && s1[i+1] != s2[i+1])) {
                if (isScramble(s1.substr(0, i+1), s2.substr(0, i+1)) && 
                    isScramble(s1.substr(i+1), s2.substr(i+1)))
                    return true;
            }
            if (s1charCount == s2charCount2 && (s1[i] != s2[j] || rightLeftMatch && s1[i+1] != s2[j-1])) {
                if (isScramble(s1.substr(0, i+1), s2.substr(j)) && 
                    isScramble(s1.substr(i+1), s2.substr(0, j)))
                    return true;
            }
        }
        memo[s1][s2] = leftRightMatch || rightLeftMatch;
        return leftRightMatch || rightLeftMatch;
    }
};