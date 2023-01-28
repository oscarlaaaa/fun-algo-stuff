// 2023-01-27 (double map)
class SummaryRanges {
/*
    input: datastream of non-negative integers
    outputs:
        - addNum(val): adds a num to our stream
        - getIntervals(): returns a summary of ints in the stream sorted by start
    
    notes:
    - addNum's val can be 0 to 10^4
    - main issue is definitely merging intervals together
        - maybe using binary search to find insertion points? (lower_bound maybe)
    - 3 * 10^4 calls to addNum and/or getIntervals
    - maybe have them do different things?
        - addNum inserts into place
        - getIntervals merge together
    - how do we want to store the intervals?
        - if we use a sorted set:
            - O(logn) insertion
            - O(n) to return getIntervals (could collapse intervals as well for efficiency, but how to remove while
              iterating over the set??)
        - if we use a vector (but seems too simple??):
            - O(n) insertion
            - O(1) to return getIntervals
        - if we use a sorted map:
            - same as sorted set (except we wouldnt store pairs)
        - what if we use 2 maps?
            - O(logn) insertion + merge
            - O(n) to return getIntervals

    approach:
    - utilize 2 maps to keep track of starts and ends separately
        - starts uses a sorted map to generate the getIntervals() vector easily, while ends uses an
          unordered map for ease of use
        - starts holds <startVal, endVal> while ends holds <endVal, startVal> for ease in merging
    - hold an "added" set to keep track of values we've already added (double-adding will make it complicated)
    - addNum(value):
        - check if we've added before, and skip if so
        - check our "ends" map if value-1 exists, and merge if so
            - use the value stored in the "ends" map to erase the entry from "starts"
            - set the stored start as our new interval start value
        - check our "starts" map if value+1 exists, and merge if so
            - use value stored in "starts" map to erase from "ends"
            - set the stored end as our new interval end value
        - re-insert the new pair within both maps
    - getIntervals():
        - iterate over our sorted map, and just place them into an output list to return
*/
public:
    map<int, int> starts;
    unordered_map<int, int> ends;
    unordered_set<int> added;
    SummaryRanges() {}
    
    void addNum(int value) {
        if (added.count(value))
            return;
        added.insert(value);
        int start = value, end = value;

        // merge if an interval ends at value-1 ([X, value-1], [value, value])
        if (ends.count(value-1)) {
            start = ends[value-1];
            starts.erase(ends[value-1]);
            ends.erase(value-1);
        }

        // merge if an interval starts at value+1 ([value, value], [value+1, X])
        if (starts.count(value+1)) {
            end = starts[value+1];
            ends.erase(starts[value+1]);
            starts.erase(value+1);
        }

        starts.insert({start, end});
        ends.insert({end, start});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> output;
        for (auto [start, end] : starts) {
            output.push_back({start, end});
        }
        return output;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */