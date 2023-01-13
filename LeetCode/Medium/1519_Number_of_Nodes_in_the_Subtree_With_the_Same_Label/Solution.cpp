class Solution {
public:
    vector<vector<int>> children;
    string nodeLabels;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        /*
            input: int n nodes of a tree, edges between trees, and a string labels
            output: list of size n where output[i] = nodes in ith node subtree with the same label

            notes:
            - could approach it per character and use up O(nm) time, but we dont do that here B)
            - subtree of a node includes itself; every position in output has at least 1
            - keep a set of letter counts that is passed upwards from the leaf?
                - each node merges the letter counts from its children?
            - only up to 26 labels (lowercase english)
            - root is always node 0
            
            approach:
            - create adj list and DFS downwards starting from node 0
            - for each node, intialize label counts and call recursive function for its children to get
              the label counts from each children
            - merge all label counts into 1, assign the current label count to the output

            analysis:
            - time = O(n) where n=number of nodes
            - space = O(n+h) where n=number of nodes and h=height of the tree
        */
        children = vector<vector<int>>(n);
        nodeLabels = labels;
        for (vector<int>& edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }

        vector<int> output(n);
        findSameLabels(0, -1, output);
        return output;
    }

    int* findSameLabels(int node, int parent, vector<int>& output) {
        int labelCounts[26] = {0};
        labelCounts[nodeLabels[node]-'a']++;
        for (int child : children[node]) {
            if (child == parent) 
                continue;
            int* childLabels = findSameLabels(child, node, output);
            for (int i=0; i<26; i++) {
                labelCounts[i] += childLabels[i];
            }
        }
        output[node] = labelCounts[nodeLabels[node]-'a'];
        return labelCounts;
    }
};