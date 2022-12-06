// 2022-12-03 (BFS approach)
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        /*
            input: number of cities, and roads where [to, from, distance]
            output: minimum score of a path between two cities

            notes:
            - minimum score = minimum dist between 2 cities within a path
            - i didn't read it clearly, and i didnt note that you can visit the same 
                road multiple times
            - because you can traverse the same road multiple times, there's no downside
                to exploring every single city possible and finding the shortest road
            - boils down to finding a connected component of the graph with 1 and n and returning
                the smallest road found within that component
            
            approach:
            - create adjacency list
            - BFS to see which cities are connected to 1 and n
            - find the minimum of all paths involving our cities found above and return
        */
        vector<vector<int>> adjList(n+1), weights(n+1);
        for (vector<int> &road : roads) {
            adjList[road[0]].push_back(road[1]);
            adjList[road[1]].push_back(road[0]);
            weights[road[0]].push_back(road[2]);
        }
        
        vector<bool> visited(n+1);
        deque<int> queue(1, 1);
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop_front();
            visited[node] = true;
            for (int neighbour : adjList[node]) {
                if (!visited[neighbour]) {
                    queue.push_back(neighbour);
                }
            }
        }
        
        int minimum = INT_MAX;
        for (int i=0; i<n+1; i++) {
            if (!visited[i]) continue;
            for (int val : weights[i]) {
                minimum = min(minimum, val);
            }
        }

        return minimum; 
    }
};