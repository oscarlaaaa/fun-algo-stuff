// 2023-04-10 (memoized DFS)
class Solution {
private:
    vector<vector<int>> colourCount;
    bool validCycleCount(vector<vector<int>>& neighbours, int node, string& colours, vector<bool>& path) {
        /*
            returns false if the graph has a cycle
        */
        // cycle detected
        if (path[node]) return false;
        
        // memoized count present
        if (colourCount[node][26]) return true;

        // mark current node as visited and add to path
        path[node] = true;
        colourCount[node][26] = true;
        for (int neigh : neighbours[node]) {
            // explore neighbours
            if (!validCycleCount(neighbours, neigh, colours, path))
                return false;
            // only take the max counts from each possible route
            for (int i=0; i<26; i++)
                colourCount[node][i] = max(colourCount[node][i], colourCount[neigh][i]);
        }
        
        colourCount[node][colours[node]-'a']++;
        path[node] = false;
        return true;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        /*
        notes:
        - info:
            - n nodes and m edges
            - each node has a colour represented with a lowercase letter
            - directed edges
            - colour value of a path = max frequency of a single colour
        - possibly cyclic so that could pose to be an issue
            - being directed kinda helps it? as cycles should be less frequent
            - actually we jsut return -1 if there is a cycle so probably detect
              for a cycle first before doing anything
        - detect cycle first
            - detect using DFS and backtracking?
            - keep track of current iteration vs previously seen
                - cycles only if we revisit from current iteration
        - find path counts
            - need to visit every non-visited node to ensure we don't miss any cycles
            - each node takes the max counts from each neighbour since we're just looking
              for the max count of a single colour; don't need to care if the recorded 
              colour counts represent the same path
        
        - time = O(v+e) where v=nodes and e=edges
        - space = O(v) where v=nodes
        */
        int n = colors.length();
        
        // mark starting nodes and neighbours
        vector<vector<int>> neighbours(n, vector<int>());
        for (vector<int>& edge : edges) {
            neighbours[edge[0]].push_back(edge[1]);
        }
        
        // first 26 indices are for counts; last one is whether we've visited
        colourCount = vector<vector<int>>(n, vector<int>(27));

        // detect if cycle part 2 and count colours
        int maxVal = 0;
        for (int i=0; i<n; i++) {
            vector<bool> path(n); 
            if (!colourCount[i][26] && !validCycleCount(neighbours, i, colors, path))
                return -1; 
            maxVal = max(maxVal, *max_element(colourCount[i].begin(), colourCount[i].end()));    
        }           
        
        return maxVal;
    }
};

// 2023-04-10 (topological sort)
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        /*
        notes:
        - info:
            - n nodes and m edges
            - each node has a colour represented with a lowercase letter
            - directed edges
            - colour value of a path = max frequency of a single colour
        - topological sort approach to process in order
            - queue up all nodes with 0 in-degrees
            - add current colour count to the node, and push the max values
              of each count onto each neighbour
            - decrement the neighbour's in-degrees and queue if it's at 0 since
              it means all nodes pointing towards it have been processed already
        
        - time = O(v+e) where v=nodes and e=edges
        - space = O(v) where v=nodes
        */
        int n = colors.length();
        vector<int> inDegrees(n);
        vector<vector<int>> neighbours(n);
        for (vector<int>& edge : edges) {
            neighbours[edge[0]].push_back(edge[1]);
            inDegrees[edge[1]]++;
        }

        deque<int> queue;
        for (int i=0; i<n; i++) {
            if (inDegrees[i] == 0)
                queue.push_back(i);
        }

        unordered_set<int> seen;
        vector<vector<int>> colourCounts(n, vector<int>(26));
        int maxVal = 1;
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop_front();

            seen.insert(node);
            colourCounts[node][colors[node]-'a']++;
            for (int neigh : neighbours[node]) {
                for (int i=0; i<26; i++) {
                    colourCounts[neigh][i] = max(colourCounts[neigh][i], colourCounts[node][i]);
                }
                inDegrees[neigh]--;
                if (inDegrees[neigh] == 0)
                    queue.push_back(neigh);
            }
            
            maxVal = max(maxVal, *max_element(colourCounts[node].begin(), colourCounts[node].end()));
        }
        return seen.size() == n ? maxVal : -1;
    }
};