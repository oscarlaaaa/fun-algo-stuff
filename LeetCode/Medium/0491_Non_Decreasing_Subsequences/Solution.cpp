// 2023-01-19 (recursive back-tracking)
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        /*
            input: a list of ints
            output: all possible non-decreasing subsequences with at least 2 elements

            notes:
            - looks like no repeats allowed
            - looks like a backtracking thing? I would say DP but the max length of nums is kind short
            - probably backtracking

            approach:
            - create a recursive function to hold current subsequences
                - function will hold nums, a current position, and a current path
                - iterate from current position until a larger/equal value is found
                    - add to our current path, add to our set, and send it recursively down
                - remove val from the end of our current path after recursion is done, and continue
                - if path is ever >= length of 2, then we add to our answers vector
            - return a stored answers vector

            analysis:
            - time: O(2^n) where n = length of nums
            - space: O(n) where n = length of nums (not including output)
        */
        vector<vector<int>> output;
        vector<int> curSubsequence;
        findNonDecreasing(nums, 0, curSubsequence, output);
        return output;
    }

    void findNonDecreasing(vector<int>& nums, int pos, vector<int>& curSubsequence, vector<vector<int>>& output) {
        if (curSubsequence.size() >= 2)
            output.push_back(vector<int>(curSubsequence.begin(), curSubsequence.end()));
        
        unordered_set<int> seen;
        for (int i=pos; i<nums.size(); i++) {
            if (!seen.count(nums[i]) && (curSubsequence.empty() || curSubsequence.back() <= nums[i])) {
                seen.insert(nums[i]);
                curSubsequence.push_back(nums[i]);
                findNonDecreasing(nums, i+1, curSubsequence, output);
                curSubsequence.pop_back();
            }
        }
    }
};