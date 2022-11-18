// 2022-11-18 (union find)
class Solution {
public:
    int findParentAndSquash(vector<int>& disjoints, int target) {
        if (disjoints[target] != target)
            disjoints[target] = findParentAndSquash(disjoints, disjoints[target]);
        return disjoints[target];
    }
    int removeStones(vector<vector<int>>& stones) {
        /*
        input: list of coordinates with stones
        output: max number of stones we can remove

        approach:
        - group stones into disjoint sets, and number of stones = number of sets
            - new vector to hold different stones
                - points to either another index in vector that it is under, or -1 for root of its own
            - two maps, rows and cols, where key = row/col num and val = index in vector it points to
            - add new int to our vector (value of its own index) if we encounter a new row/col, and assign the
              new row/col to point to that stone
            - squash hierarchies when finding parent set
            - return number of stones - num of disjoint parent sets
        */
        vector<int> disjoints;
        unordered_map<int, int> rows, cols;

        for (int i=0; i<stones.size(); i++) {
            vector<int> stone = stones[i];
            if (!rows.count(stone[0]) || !cols.count(stone[1])) {
                rows[stone[0]] = (rows.count(stone[0]) ? rows[stone[0]] : disjoints.size()); 
                cols[stone[1]] = (cols.count(stone[1]) ? cols[stone[1]] : disjoints.size()); 
                disjoints.push_back(disjoints.size());
            }

            int rowParent = findParentAndSquash(disjoints, rows[stone[0]]); 
            int colParent = findParentAndSquash(disjoints, cols[stone[1]]); 

            // row and col are separate
            if (rowParent != colParent) {
                disjoints[rowParent] = disjoints[colParent];
            }
        }

        unordered_set<int> dj;
        int numDisjoint = 0;
        for (int val : disjoints) {
            int parent = findParentAndSquash(disjoints, val);
            if (!dj.count(parent)) {
                dj.insert(parent);
                numDisjoint++;
            }
        }
        return stones.size() - numDisjoint;
    }
};