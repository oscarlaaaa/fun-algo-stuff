// 2022-12-20 (BFS)
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        /*
            input: n number of people, and a list of dislike relationships
            output: whether we can split the people into 2 groups

            notes:
            - all dislike pairs are unique
            - people who dislike each other should not be placed in the same group
            - kinda like reverse union find?

            approach:
            - create an adjacency list to represent it as a graph
            - when we traverse the graph, can mark each node as either team0 or team1
            - if we encounter a node that needs to be assigned a conflicting team, then
              we return false
            - use BFS and make each relationship bidirectional to ensure we cover all connected
              people in one go
        */
        // create adjacency lists
        vector<vector<int>> adjList(n+1);
        for (vector<int>& dislike : dislikes) {
            int p1 = dislike[0], p2 = dislike[1];
            adjList[p1].push_back(p2);
            adjList[p2].push_back(p1);
        }

        vector<int> assignedTeam(n+1, -1);
        for (int i=1; i<=n; i++) {
            if (assignedTeam[i] != -1) 
                continue;

            deque<pair<int, int>> queue = {{i, 0}};
            while (!queue.empty()) {
                auto [person, team] = queue.front();
                queue.pop_front();

                for (int dislike : adjList[person]) {
                    if (assignedTeam[dislike] != -1) {
                        // if the neighbour is on a different team, then its gucci
                        if (assignedTeam[dislike] == team^1)
                            continue;
                        // otherwise, there is a conflict and separating isn't possible
                        return false;
                    }
                    queue.push_back({dislike, team^1});
                }

                assignedTeam[person] = team;
            }
        }

        return true;
    }
};