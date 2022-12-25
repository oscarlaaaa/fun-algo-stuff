// 2022-12-24 (heaps)
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        /*
            input: list of nums length n, and list of queries length m
            output: list of int length m where answer[m] = max subsequence size from nums that is
                    less than or equal to queries[i]
            
            notes:
            - nums and queries not guaranteed to be sorted
            - could heap them up? can't sort queries since that'd mess up order of answer
              - could get a list of indices and sort using custom comparator
            - have to sort nums regardless
            - use a PQ to organize nums

            approach:
            - keep track of a total sum
            - use heaps to organize nums by value (lowest on top), and queries by value (but hold indices 
              as well for output)
              - hold queries in pairs for easy heap comparison
            - for each query (smallest to largest), pop off nums until our total will exceed the query
              value, then store the pop count into the output list in the correct index
        */
        int n = nums.size(), m = queries.size();
        priority_queue<int, vector<int>, greater<int>> numHeap;
        for (int i=0; i<n; i++)
            numHeap.push(nums[i]);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queryHeap;
        for (int i=0; i<m; i++)
            queryHeap.push({queries[i], i});
        
        vector<int> output(m);
        int total = 0, count = 0;
        while (!queryHeap.empty()) {
            auto [query, idx] = queryHeap.top();
            queryHeap.pop();

            while (!numHeap.empty() && total + numHeap.top() <= query) {
                total += numHeap.top();
                count++;
                numHeap.pop();
            }
            output[idx] = count;
        }
        return output;
    }
};