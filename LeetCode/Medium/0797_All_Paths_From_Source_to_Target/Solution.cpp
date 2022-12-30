// 2022-12-29 (iterative DFS)
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        /*
            input: an adjacency list of a directed acyclic graph
            output: all possible paths from node 0 to node n-1

            notes:
            - acyclic, so don't need to worry about cycles
            - most likely just backtracking DFS, starting from node 0
            - adjacency list is made for us! yay!
            
            approach:
            - keep a stack of pair<current node, current path> and perform iterative DFS
            - store our current node into the current path up to the node
            - every time we reach the end node, store the path into an output vector
            - otherwise, just push the neighbour + path into our stack and continue
        */
        int n = graph.size();
        vector<vector<int>> output;
        deque<pair<int, vector<int>>> stack = {{0, {}}};
        while (!stack.empty()) {
            auto [node, path] = stack.back();
            stack.pop_back();
            path.push_back(node);
            if (node == n-1) {
                output.push_back(path);
            } else {
                for (int neighbour : graph[node]) {
                    stack.push_back({neighbour, path});
                }
            }
        }
        return output;
    }
};