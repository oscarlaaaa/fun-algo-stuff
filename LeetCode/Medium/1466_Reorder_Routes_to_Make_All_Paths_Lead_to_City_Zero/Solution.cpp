// 2023-03-28 (BFS)
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        /*
        notes:
        - n cities and n roads (only 1 way to travel between 2 different cities)
            - forms a tree
        - all people want to travel to city 0
        - need to reorient roads so that each city can visit city 0
            - basically flipping a road's direction, not moving it
        
        approach:
        - model as an undirected graph, but track which cities can reach which
        - DFS from 0 outwards; whenever a city isn't supposed to reach the next one,
          increment a counter
        - return the counter at the end

        analysis:
        - time = O(n)
        - space = O(n)
        */
        vector<unordered_set<int>> reachable(n), neighbours(n);
        for (vector<int>& conn : connections) {
            int a = conn[0], b = conn[1];
            reachable[a].insert(b);
            neighbours[a].insert(b);
            neighbours[b].insert(a);
        }

        int reordered = 0;
        deque<int> queue = {0};
        while (!queue.empty()) {
            int city = queue.front();
            queue.pop_front();
            for (int neigh : neighbours[city]) {
                // if neighbour can't reach current city, then we need to flip the road
                if (!reachable[neigh].count(city)) 
                    reordered++;
                neighbours[neigh].erase(city); // prevent backtracking
                queue.push_back(neigh);
            }
        }
        return reordered;
    }
};