// 2023-01-12 (DFS)
class Solution {
public:
    int curLongest = 1;
    int longestPath(vector<int>& parent, string s) {
        /*
            input: a list of node parents parent[i] = i's parent, and a string s
            output: the longest path in the tree where no adjacent nodes have the same char

            notes:
            - seems like something where we run the recurisve funcion on the children,
              and pass up maybe the single longest path that starts at the current node up?
            - will probably need a variable on the side to hold our global answer
            - node 0 is always the root
            - probably generate an adjacency list first to make it easier
            
            approach:
            - create an adjacency list to make iterating easier
            - create a recursive function that both returns the longest path starting at the current
              node + assigns the current best answer to the global variable
                - need parameters for adj list, node, parent (to prevent backtracking)
                - get return values from each child, and merges with total length if child val != cur val
                - return either 1 if node matches both children, or 1 + longest child length if not
            - return our global variable afterwards

            analysis:
            - time: O(n) where n=number of nodes
            - space: O(n) where n=number of nodes
        */
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i=1; i<n; i++) {
            children[parent[i]].push_back(i);
        }

        findLongest(children, 0, -1, s);
        return curLongest;
    }

    int findLongest(vector<vector<int>>& children, int node, int parent, string& s) {
        int singleLongest = 1;
        for (int child : children[node]) {
            if (child == parent)
                continue;
            int length = findLongest(children, child, node, s);
            // if we can connect our child length to our current node
            if (s[child] != s[node]) {
                // only record our longest connected child; greedily find new curLongest using this
                curLongest = max(curLongest, singleLongest+length);
                singleLongest = max(singleLongest, 1+length);
            }
        } 
        return singleLongest;  
    }
};