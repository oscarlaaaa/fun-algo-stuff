// 2022-01-10 (DFS)
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        /*
            input: int n number of nodes, edges between vertices, and whether a node has an apple
            output: minimum time to grab every apple in the tree and return to vertex 0

            notes:
            - our answer will awlways be an even number; we need to double back to 
              return to the previous vertex every time
            - DFS to find the distance of every apple?
            - Could sum up number of steps to grab apples under it for each node, then pass
              the sum+2 up wards
            - rely on the call stack (if recursive) to return values up instead of trying to traverse
              back upwards would probably be better
            
            approach:
            - recursive function that finds distance of all apples for the node
                - basically find distance of apples from child + 2 (if any)
            - return the distance upwards for parents to grab
                - if we have no apples, return -1 so parent nodes can ignore us :(
            - only function parameters needed are the current node, the children list, and hasApple
                - actually, we need the parent node as well to prevent backtracking causing an infinite
            
            analysis:
            - time = O(n) where n=number of nodes
            - space = O(h) where h=height of the tree (due to call stacK)
        */
        vector<vector<int>> children(n);
        for (vector<int>& edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }

        int apples = findMinAppleTime(-1, 0, children, hasApple);
        return max(0, apples);
    }

    int findMinAppleTime(int parent, int node, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int total = hasApple[node] ? 0 : -1;
        
        for (int child : edges[node]) {
            if (child == parent)
                continue;

            int childApples = findMinAppleTime(node, child, edges, hasApple);
            if (childApples > -1) {
                total = max(total, 0);
                total += childApples+2;
            }
        }
        return total;
    }
};