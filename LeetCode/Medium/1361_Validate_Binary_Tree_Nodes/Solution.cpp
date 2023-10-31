// 2023-10-16 (dfs)
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        /*
        notes:
        - n binary tree nodes where each has two children
        - return whether the tree is a valid binary tree node
        - basically need to check that:
            - each node only has 1 parent: just check that we can traverse everything with no loops
            - all nodes are connected as 1 binary tree: union find?
        - maybe DFS while tracking which nodes we've encountered that have parents
            - hit something we've already seen = either a loop OR child with 2 parents
        
        analysis:
        - time = O(n)
        - space = O(n)
        */
        unordered_set<int> hasParent;
        for (int i=0; i<n; i++) {
            // nodes with more than 1 parent indicate directed graphs, not bts
            if (hasParent.contains(leftChild[i]) || hasParent.contains(rightChild[i]))
                return false;

            if (leftChild[i] != -1) 
                hasParent.insert(leftChild[i]);
            
            if (rightChild[i] != -1) 
                hasParent.insert(rightChild[i]);
        }

        // there can only be one node without a parent to be a valid bt
        if (hasParent.size() != n-1)
            return false;
        
        // DFS through starting from the root node to check connectivity
        deque<int> dfsStack;
        for (int i=0; i<n; i++) {
            if (!hasParent.contains(i))
                dfsStack.push_back(i);
        }
        unordered_set<int> seen;
        while (!dfsStack.empty()) {
            int node = dfsStack.back();
            dfsStack.pop_back();

            seen.insert(node);
            if (leftChild[node] != -1) {
                dfsStack.push_back(leftChild[node]);
            }
            if (rightChild[node] != -1) {
                dfsStack.push_back(rightChild[node]);
            }
        }

        // unreachable nodes = a disconnected bt/graph/etc.
        return seen.size() == n;     
    }
};