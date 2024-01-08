// 2024-01-03
class Solution {
public:
    int minOperations(vector<int>& nums) {
        /*
        notes:
        - can either delete 2 or 3 elements from the array
        - want to make the array empty
        - we can just count # of occurrences of each value, and it's doable
          as long as the # of elements are at least 2
        - # operations to clear out would be N/3 if N%3 == 0, or N/3 + 1 if N%3 == 1 or 2

        analysis:
        - time = O(n)
        - space = O(n)
        */
        unordered_map<int, int> numCounts;
        for (int num : nums) {
            numCounts[num]++;
        }

        int operations = 0;
        for (auto [_, count] : numCounts) {
            // not possible to remove this element
            if (count == 1) {
                return -1;
            }

            operations += count/3 + (count%3 > 0);
        }
        return operations;
    }
};