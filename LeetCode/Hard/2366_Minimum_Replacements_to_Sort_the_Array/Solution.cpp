// 2023-08-29
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        /*
        notes:
        - replace any element with any 2 that sum to it?!?!
        - needs to be broken down to the point where right > left
        - seems like we can break each element into X elements of N size
            - smallest element would be floor(element/N),
            - try to make it so that ceil(element/N) is <= the element on the right
            - breaking an element up into N elements would be N-1 operations
            - find N by doing ceil(element[i] / element[i+1])
        - iterate right to left breaking up elements when needed (i.e. left > right)

        analysis:
        - time = O(n)
        - space = O(1)
        */
        long long replacements = 0;
        int prevVal = INT_MAX;
        for (auto itr = nums.rbegin(); itr != nums.rend(); itr++) {
            if (*itr <= prevVal) {
                prevVal = *itr;
                continue;
            }

            int N = std::ceil(1.0 * (*itr)/prevVal);
            prevVal = std::floor(1.0*(*itr)/N);
            replacements += N-1;
        }
        return replacements;
    }
};