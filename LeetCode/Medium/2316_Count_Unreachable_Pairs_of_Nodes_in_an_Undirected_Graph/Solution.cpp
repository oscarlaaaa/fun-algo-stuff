// 2023-03-28 (union find)
class Solution {
public:
    void connect(vector<int>& uf, int node1, int node2) {
        int parent1 = find(uf, node1), parent2 = find(uf, node2);
        uf[parent1] = parent2;
    }
    int find(vector<int>& uf, int node) {
        if (node != uf[node])
            uf[node] = find(uf, uf[node]);
        return uf[node];
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        /*
        notes:
        - want to return the number of pairs of nodes that are unreachable
          from each other
        - isnt this basically unionfind and multiplying groups together?
        - find size of each disconnected group and then mutliply size * n-size

        analysis:
        - time = O(nlogn)
        - space = O(n)
        */
        vector<int> uf(n);
        for (int i=0; i<n; i++)
            uf[i] = i;
        
        // connect nodes
        for (vector<int>& edge : edges) {
            connect(uf, min(edge[0], edge[1]), max(edge[0], edge[1]));
        }

        // count distinct parents
        vector<int> groups(n);
        for (int i=0; i<n; i++) {
            int parent = find(uf, i);
            groups[parent]++;
        }
        long long output = 0, remaining = n;
        for (int i=0; i<n; i++) {
            remaining -= groups[i];
            output += remaining * groups[i];
        }
        return output;       
    }   
};