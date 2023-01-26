// 2023-01-25 (tabulation DP)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        /*
            input: n cities, a list of flights, a source, destination, and k stops max
            output: the cheapest price from the source to destination

            notes:
            - textbook djikstras probably (maybe not actually since there is a K limit)
                - at most K stops makes it a little different
            - is this just simple BFS with backtracking?
            - only perform K iterations
                - do we even need to handle loops in this case? since K iterations will make it terminate anyways
            - we could probably throw a set in with each BFS call?
            - the above doesn't work; turns out this is DP (key part is the K flights max)

            approach:
            - create list of flight connections to make it easy to parse
            - create a grid of size n * k+2, as k=max stops and doesn't include the start/end
                - grid[i][j] hold the cheapest cost to reach the city j in i stops
                - initialize all with INT_MAX except grid[0][src] as its our starting city
            - iterate over our grid with 2 for loops (i <= k, and j < n)
                - if grid[i][j] == INT_MAX, then continue as we cannot reach it at this point
                - otherwise, send flights out to all reachable cities and assign minimum values to cells
                    - record cheapest flights to dst to save trouble later
            - return our cheapest recorded
        */
        vector<vector<pair<int, int>>> flightConnections(n, vector<pair<int, int>>());
        vector<vector<int>> shortest(k+2, vector<int>(n, INT_MAX));
        for (vector<int>& flight : flights) {
            flightConnections[flight[0]].push_back({flight[1], flight[2]});
        }
        shortest[0][src] = 0;

        int cheapest = INT_MAX;
        for (int stops=0; stops<=k; stops++) {
            for (int city=0; city<n; city++) {
                if (shortest[stops][city] == INT_MAX) 
                    continue;

                for (auto [target, cost] : flightConnections[city]) {
                    shortest[stops+1][target] = min(shortest[stops+1][target], shortest[stops][city]+cost);
                    if (target == dst)
                        cheapest = min(cheapest, shortest[stops+1][target]);
                }
            }
        }

        return cheapest == INT_MAX ? -1 : cheapest;
    }
};