// 2023-01-22 (in and out-degree of graph)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        /*
            input: n people, and a list of trust relationships
            output: the town judge's label, or -1 if doesn't exist

            approach:
            - seems like we want to track 2 things:
                - how many people a person trusts
                - how many people a person is trusted by
            - track using 2 vectors
            - iterate thru the vectors, and find one where # people trusts = 0 and
              # people trusted by = n-1, and return the index

            analysis:
            - time: O(n)
            - space: O(n)
        */
        int m = trust.size();
        vector<int> trusts(n+1), trustedBy(n+1);
        for (int i=0; i<m; i++) {
            trusts[trust[i][0]]++;
            trustedBy[trust[i][1]]++;
        }
        for (int i=1; i<=n; i++) {
            if (trusts[i] == 0 && trustedBy[i] == n-1)
                return i;
        }
        return -1;
    }
};