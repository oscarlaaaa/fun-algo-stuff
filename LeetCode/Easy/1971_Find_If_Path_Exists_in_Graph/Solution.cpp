// 2022-12-18 (BFS)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        /*
            input: number of vertices, list of edges, a source, and a target destination
            output: whether source and destination are connected

            approach:
            - build an adjacency list to keep track of connections
            - BFS from the source and see if we can reach the destination
                - return true if we do
            - if we've completed BFS from  the source without reaching, return false
        */
        vector<vector<int>> adjList(n);
        for (vector<int> edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n);
        deque<int> queue = {source};
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop_front();

            if (node == destination) 
                return true;
            
            visited[node] = true;
            for (int neighbour : adjList[node]) {
                if (!visited[neighbour])
                    queue.push_back(neighbour);
            }
        }
        return false;
    }
};