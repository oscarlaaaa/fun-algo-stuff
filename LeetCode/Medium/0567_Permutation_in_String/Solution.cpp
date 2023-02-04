// 2023-02-03 (sliding window)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
            input: two strings s1 and s2
            output: whether s2 contains a permutation of s1

            notes:
            - permutation just means all available chars, so seems simple enough
            - probably sliding window approach?
            - maybe insert all s1 chars into a map to keep track of counts
            
            approach:
            - keep track of all char counts in s1 using a map
                - keep track of chars within our window using a separate map
            - 2-pointer sliding window across s2 using an l and r pointer
                - if s2[r] is needed, then add to our map
                - otherwise if s2[r] is not needed, increment l pointer forward and 
                  remove from our "have" map until we need s2[r] again
                    - if s2[i] not in our need map at all, we can just reset and skip it
                    - otherwise, continue iterating
            - return true if our maps match, false if we finish our loop without matching maps

            analysis:
            - time: O(n) where n=length of s2
            - space: O(1) since we're limited to 26 lowercase chars in our map
        */
        unordered_map<char, int> needCounts, haveCounts;
        for (int i=0; i<s1.length(); i++) {
            needCounts[s1[i]]++;
        }

        int n = s2.length();
        for (int l=0, r=0; r<n; r++) {
            // if we have the wrong char at the front, do a full reset and skip
            if (!needCounts.count(s2[r])) {
                haveCounts.clear();
                l = r+1;
            // if we would over-count one char, shrink window until we won't
            } else if (haveCounts[s2[r]] >= needCounts[s2[r]]) {
                while (l < r && haveCounts[s2[r]] >= needCounts[s2[r]]) {
                    haveCounts[s2[l]]--;
                    l++;
                }
                r--; // prevent accidently skipping the current char
            // otherwise, add to our counts and check if we've found a permutation
            } else {
                haveCounts[s2[r]]++;
                if (needCounts == haveCounts)
                    return true;
            }
        }
        return false;
    }
};