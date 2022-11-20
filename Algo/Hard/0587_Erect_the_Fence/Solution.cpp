// 2022-11-18 (monotonic-stack)
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        /*
        input: list of tree coordinates
        output: trees that are located on the fence perimeter

        notes:
        - need to keep track of the outer-most trees present
        - need at least 4 trees to have output != trees
        - organize trees into rows and columns, and sort
        - iterate through columns
            - first and last columns will have all trees touching the perimeter
            - all other columns in the center will only touch perimeter if they meet the following:
                - greater than the previous column's greatest, and current-prev > next-current
                - less than the previous column's least, and prev-current > current-next
                - keep track using a stack? differences need to be monotonic

        approach:
        - bucket sort all trees
        - iterate from lowest index column to greatest
            - first and last column includes all trees
            - monotonic stack decreasing from left->right for top trees 
            - monotonic stack increasing from left->right for bottom trees
        - only add non-duplicate trees to output
        */

        // bucket sort all trees
        vector<vector<int>> columns(101);
        for (vector<int> tree : trees) {
            columns[tree[0]].push_back(tree[1]);
        }

        // get highest and lowest row of each column, and place within respective lists
        vector<vector<int>> top, bottom;
        for (int i=0; i<101; i++) {
            if (!columns[i].empty()) {
                top.push_back({i, *max_element(columns[i].begin(), columns[i].end())});
                bottom.push_back({i, *min_element(columns[i].begin(), columns[i].end())});
            }
        }

        deque<double> lastSlopeInc = {INT_MAX}, lastSlopeDec = {INT_MIN};
        deque<vector<int>> lastTreeInc = {top[0]}, lastTreeDec = {bottom[0]};

        // create a list of top trees where the slopes between each are decreasing
        for (int i=1; i<top.size(); i++) {
            double slope = (double) (top[i][1] - lastTreeInc.back()[1]) / (top[i][0] - lastTreeInc.back()[0]);
            while (!lastSlopeInc.empty() && lastSlopeInc.back() < slope) {
                lastSlopeInc.pop_back();
                lastTreeInc.pop_back();
                slope = (double) (top[i][1] - lastTreeInc.back()[1]) / (top[i][0] - lastTreeInc.back()[0]);
            }
            lastSlopeInc.push_back(slope);
            lastTreeInc.push_back(top[i]);
        }

        // create a list of bottom trees where the slopes between each are increasing
        for (int i=1; i<bottom.size(); i++) {
            double slope = (double) (bottom[i][1] - lastTreeDec.back()[1]) / (bottom[i][0] - lastTreeDec.back()[0]);
            while (!lastSlopeDec.empty() && lastSlopeDec.back() > slope) {
                lastSlopeDec.pop_back();
                lastTreeDec.pop_back();
                slope = (double) (bottom[i][1] - lastTreeDec.back()[1]) / (bottom[i][0] - lastTreeDec.back()[0]);
            }
            lastSlopeDec.push_back(slope);
            lastTreeDec.push_back(bottom[i]);
        }

        vector<vector<int>> output;

        // add all trees from first/last columns into output
        int l = 0, r = 100;
        while (l < 101 && columns[l].empty()) l++;
        while (r >= 0 && columns[r].empty()) r--;
        for (int row : columns[l]) {
            output.push_back({l, row});
        }
        for (int row : columns[r]) {
            output.push_back({r, row});
        }

        // add all top/bottom trees into output
        for (vector<int> tree : lastTreeInc) {
            output.push_back(tree);
        }
        for (vector<int> tree : lastTreeDec) {
            output.push_back(tree);
        }

        // remove all duplicates
        vector<vector<bool>> seen(101, vector<bool>(101, false));
        vector<vector<int>> noDupes;
        for (vector<int> tree : output) {
            if (!seen[tree[0]][tree[1]]) {
                seen[tree[0]][tree[1]] = true;
                noDupes.push_back(tree);
            }
        }
        
        return noDupes;
    }
};