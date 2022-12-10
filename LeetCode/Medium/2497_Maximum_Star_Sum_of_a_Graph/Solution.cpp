// 2022-12-10
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        /*
            input: values of nodes 1 to n-1, a vector of edges, and k
            output: sum of a subgraph of a single node + up to k neighbours

            approach:
            - create a vector of neighbour weights for each node
            - for each edge, store each node's neighbour's weight in its vector
            - sort the weight lists to make it descending order
            - iterate through the neighbour weight lists, and either take the sum of
              k values, or until taking neighbours stops being useful towards the total
        */
        vector<vector<int>> neighborWeights(vals.size());
        for (vector<int>& edge : edges) {
            neighborWeights[edge[0]].push_back(vals[edge[1]]);
            neighborWeights[edge[1]].push_back(vals[edge[0]]);
        }
        
        int maxim = vals[0];
        for (int i=0; i<neighborWeights.size(); i++) {
            sort(neighborWeights[i].begin(), neighborWeights[i].end(), [](int& a, int& b) {
                return a > b;
            });
            int total = vals[i];
            for (int j=0; j<k && j<neighborWeights[i].size(); j++) {
                if (total+neighborWeights[i][j] < total) 
                    break;
                total += neighborWeights[i][j];
            }
            maxim = max(total, maxim);
        }
        return maxim;
    }
};