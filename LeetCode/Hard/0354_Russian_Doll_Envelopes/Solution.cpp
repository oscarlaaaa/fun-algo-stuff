// 2022-05-28 (sort + dp)
/**
 * 
 * The key to this approach is sorting the envelopes by one value in ascending order,
 * and the other in descending order. This way, we can ensure that if we sorted it by
 * width ascending and heights descending, any increase in height will also come with
 * an increase in width.
 * 
 * We keep track of a list of heights that we have in ascending order.
 * Every envelope we iterate over, we want to check if there are any values in our
 * heights list greater than our current height.
 *  - If we have something greater, we can replace it with the current val to keep track of
 *    another possible path
 *  - If its the largest, then we can append it to the end as the next envelope
 * 
 * Replacing values not at the end of heights doesn't matter as new heights greater
 * than our new heights would also be greater than our previous heights;
 * starting an iteration from [2, 9] would have >= iterations as [6, 9], so keeping
 * old values is ok
 * 
 */
class Solution {
public:
    // key is to sort one in ascending and another in descending
    static bool sortEnvelopes(vector<int>& v1, vector<int>& v2) {
        if (v1[0] == v2[0]) {
            return v1[1] > v2[1]; // descending
        }
        return v1[0] < v2[0]; // ascending
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), sortEnvelopes);
        vector<int> heights;

        for (vector<int> e : envelopes) {
            if (heights.size() == 0) {
                heights.push_back(e[1]);
            } else {
                // find the first element where height >= current height
                auto itr = lower_bound(heights.begin(), heights.end(), e[1]);
                
                // if current is larger than all the heights we have, push it onto record
                if (itr == heights.end()) {
                    heights.push_back(e[1]);
                
                // if there is an element where current height is smaller/equal to something, then 
                // replace it with current height as current height has == or greater width,
                // but smaller height
                } else {
                    *itr = e[1];
                }
            }
        }
        
        return heights.size();
    }
};