// 2023-03-23 (union find)
class Solution {
public:
    class UF {
    public:
        vector<int> parents;
        UF (int n) {
            parents = vector<int>(n);
            for (int i=0; i<n; i++) {
                parents[i] = i;
            }
        }

        int find(int x) {
            if (x != parents[x])
                parents[x] = find(parents[x]);
            return parents[x];
        }   

        bool connect(int x, int y) {
            int parentX = find(x), parentY = find(y);
            if (parentX == parentY)
                return false;
            parents[parentX] = parentY;
            return true;
        }

        int numGroups() {
            int count = 0;
            unordered_set<int> seen;
            for (int p : parents) {
                int root = find(p);
                if (!seen.count(root))
                    count++;
                seen.insert(root);
            }
            return count;
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        /*
        notes:
        - looks like we need to see how many repeated wires we have (can prob
          find through union find)
        - afterwards, we just need to see how many connections involve computers
          within the same group which will be our "extra" wires
            - check by union-finding (with flattening) both comps for every connection
        - return either the number of distinct groupings if we have enough extras
          or -1

        analysis:
        - time = O(n) due to path compression
        - space = O(n)
        */

        Solution::UF *uf = new Solution::UF(n);
        int extras = 0;
        for (vector<int>& conn : connections) {
            if (!uf->connect(conn[0], conn[1]))
                extras++;
        }
        int groups = uf->numGroups();
        return groups-1 <= extras ? groups-1 : -1;
    }
};
