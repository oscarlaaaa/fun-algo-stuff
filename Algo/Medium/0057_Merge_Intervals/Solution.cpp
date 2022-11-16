// 2022-11-16 (merge in place)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /**
        input: non-overlapping intervals, sorted by start
                new interval
        output: new interval list with newInterval inserted

        notes:
        - some intervals will be merged together
        
        approach:
        - check if new interval can be inserted on either end, and insert if so
        - 2 pointer from each end that marks which to merge (all between pointers)
        - set start pointer interval to new end value, then shift remaining ones forward
        - pop off end-start intervals

        new approach:
        - iterate through
        - once we hit an interval that overlaps or is less than, send out second pointer and 
          continuously iterate until we can't merge anymore
        - if we have 0 overlap, then insert into intervals and return

        */
        int end = -1;
        int mergeSize = 0;
        for (int i=0; i<intervals.size(); i++) {
            // swap if we've already merged
            if (end != -1 && end < intervals.size()) {
                intervals[i] = intervals[end++];
            }
            if (end == -1 && max(intervals[i][0], newInterval[0]) <= min(intervals[i][1], newInterval[1])) {
                end = i;
                intervals[i][0] = min(intervals[i][0], newInterval[0]);
                intervals[i][1] = max(intervals[i][1], newInterval[1]);

                // merge current interval with as many as possible, and increment size
                while (end < intervals.size() && newInterval[1] >= intervals[end][0]) {
                    intervals[i][1] = max(intervals[end][1], intervals[i][1]);
                    end++;
                    mergeSize++;
                }
            }
        }

        // pop off all intervals that we've merged
        for (int i=0; i<mergeSize-1; i++) {
            intervals.pop_back();
        }

        // if we haven't merged, then just insert into the correct spot
        if (end == -1) {
            int insert = 0;
            while (insert < intervals.size() && newInterval[0] > intervals[insert][1]) insert++;
            intervals.insert(intervals.begin()+insert, newInterval);
        }
        
        return intervals;   
    }
};

// 2022-11-16 (merge with helper array)
class Solution2 {
public:
    bool intersects(vector<int> v1, vector<int> v2) {
        return max(v1[0], v2[0]) <= min(v1[1], v2[1]);
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        int n = intervals.size();
        int i = 0;
        while (i < n && newInterval[0] > intervals[i][1]) {
            output.push_back(intervals[i++]);
        } 
        while (i < n && intersects(newInterval, intervals[i])) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        output.push_back(newInterval);
        while (i < n) {
            output.push_back(intervals[i++]);
        }
        return output;
    }
};