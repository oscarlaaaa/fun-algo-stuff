// 2023-04-03 (greedy)
class Solution {
public:
    int partitionString(string s) {
        /*
        notes:
        - want to partition the string so that the chars in each substring are unique
            - each char should only be in one partition
        - can't we just do this greedily?
            - i don't think there's much of a difference whether a char goes in one or the other
              partition, so if we do it greedily it should still be optimal
        - thus we can prob just loop through and take any chars we haven't seen yet

        analysis:
        - time = O(n) where n=length of s
        - sapce = O(1) 
        */
        int n = s.length(), partitions = 1;
        vector<bool> seen(26);
        for (char c : s) {
            if (seen[c-'a']) {
                partitions++;
                for (int i=0; i<26; i++)
                    seen[i] = false;
            }
            seen[c-'a'] = true;
        }
        return partitions;
    }
};