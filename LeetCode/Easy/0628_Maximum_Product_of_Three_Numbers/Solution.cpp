// 2022-12-08 (heaps)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        /*
            input: vector nums
            output: maximum product from 3 numbers

            notes:
            - can do either greatest 3 values, or lowest 2 values * greatest value
            - sorting would be O(nlogn) and simpler, but we want O(n)

            approach:
            - utilze priority queues (bc we limit size, each operation is O(1))
                - one min-queue with max size 3 to get the greatest 3 values
                - one max-queue with max size 2 to get the lowest 2 values
            - pop out values and multiply all values of the greatest 3 as one value,
              and top value from greatest 3 times the lowest 2
            - return the maximum
        */
        priority_queue<int, vector<int>, greater<int>> greatest_three;
        priority_queue<int> lowest_two;
        for (int& num : nums) {
            greatest_three.push(num);
            lowest_two.push(num);

            if (greatest_three.size() > 3)
                greatest_three.pop();
            if (lowest_two.size() > 2)
                lowest_two.pop();
        }


        int two_negatives = 1, all_positive = 1;
        while (!lowest_two.empty()) {
            all_positive *= greatest_three.top();
            two_negatives *= lowest_two.top();
            greatest_three.pop();
            lowest_two.pop();
        }
        two_negatives *= greatest_three.top();
        all_positive *= greatest_three.top();
        
        return max(two_negatives, all_positive);
    }
};