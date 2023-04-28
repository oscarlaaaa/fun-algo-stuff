// 2023-04-28 (union find)
class Solution {
private:
    void connect(vector<int>& groups, int s1, int s2) {
        int p1 = find(groups, s1), p2 = find(groups, s2);
        groups[p1] = groups[p2];
    }
    int find(vector<int>& groups, int s) {
        if (groups[s] == s)
            return s;
        
        groups[s] = find(groups, groups[s]);
        return groups[s];
    }
    int numGroups(vector<int>& groups) {
        unordered_set<int> seen;
        for (int i=0; i<groups.size(); i++)
            seen.insert(find(groups, i));
        return seen.size();
    }
    int hamming(string& s1, string& s2) {
        int dist = 0;
        for (int i=0; i<s1.length(); i++) {
            if (s1[i] != s2[i])
                dist++;
        }
        return dist;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        /*
        notes:
        - strings are similar if we can swap 2 letters in one to make the other
        - every string is an anagram of every other string in the list
        - we want to form connected groups by similarity and reutnr the # of groups
        - first thing is how do we connect similar strings?

        - for each word, want to find every string that is connected to it
            - find where we only have a difference of 2 characters or less
            - form a graph, then we can union find to organize into groups
        
        analysis:
        - time = O(m*n^2) where m=length of strs[0] and n=length of strs
        - space = O(n) where n=length of strs
        */
        int n = strs.size();
        vector<int> groups(n);
        for (int i=0; i<n; i++) {
            groups[i] = i;
        }

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (hamming(strs[i], strs[j]) <= 2)
                    connect(groups, i, j);
            }
        }

        return numGroups(groups);
    }
};