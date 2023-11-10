// 2023-11-10
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        /*
        notes:
        - there are 2 possible ways; we can put it forwards or backwards
        - probably sorting somehow?
            - what if we just keep a map of chars + what they're adjacent to?
            - chars on either end only appear once, so they'd only have 1 other
              val adjacent to it so we can start at one of them
        - just build out our list from one end to the other; easy if we know an end

        analysis:
        - time = O(n)
        - space = O(n);
        */
        vector<int> output;

        // map out all adjacencies
        unordered_map<int, vector<int>> neighbours;
        for (vector<int>& pair : adjacentPairs) {
            neighbours[pair[0]].push_back(pair[1]);
            neighbours[pair[1]].push_back(pair[0]);
        }

        // find one end of the array (will have only 1 neighbour)
        int start = INT_MAX;
        for (auto &[val, adjs] : neighbours) {
            if (adjs.size() > 1) 
                continue;
            start = val;
        }

        // slowly build our list from one end to the other
        int cur = start;
        while (cur != INT_MAX) {
            vector<int>& nextNeighbours = neighbours[cur];

            // we prevent backtracking by making sure we don't add whatever
            // we've added prior
            int nextNeighbour = INT_MAX;
            if (!output.size() || output.back() != nextNeighbours.front()) {
                nextNeighbour = nextNeighbours.front();
            } else if (output.back() != nextNeighbours.back()) {
                nextNeighbour = nextNeighbours.back();
            }

            output.push_back(cur);
            cur = nextNeighbour;
        }

        return output;
    }
};
