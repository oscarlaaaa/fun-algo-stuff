// 2023-02-28 (sets)
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        /*
            input: an array of n positive integers
            output: the minimum deviation after performing the operations

            operations:
            - if it's even, divide it by 2
            - if it's odd, multiply it by 2

            notes:
            - there is some sort of happy median we can reach with our values
                - the difficulty comes when a value can flip flop between odd/even, and
                  we can perform multiple operations on one value
                - i.e. 20 -> 10 -> 5 -> 10
                    - seems like there is a lower bound for all numbers, but no upper bound
                      (since multiplying anything by 2 is always an even number)
            - maybe we should find the bounds for all values?
                - numbers can only go up once (any number * 2 = an even number), and down until it becomes odd
                - maybe raise everything to its highest possible? then dropping down
                    - hold evens and odds in different piles, and see if any operations can reduce the bounds of the
                      highest values?
                        - if we use sets, we can ignore duplicates since they're essentially the same
            - doubling 2 elements will always make them further apart (higher element increases by larger factor),
              so we should have some idea of whether a value is worth doubling or not

            approach:
            - process nums by multiplying all of them by 2 if possible to hit the highest limit
            - keep 2 sets: one for odds and one for evens
            - while loop to process:
                - if upper bound of even > upper bound of odd, then halve it and re-store new value
                - process until we either run out of evens or there is an odd that is greeater than our next even
                  (since odds can't be divided, that sets our limit for the lowest upper bound possible)
            
            analysis:
            - time = O(nlogn) where n=length of nums
            - space = O(n) where n=length of nums
        */
        int n = nums.size();
        set<int> odds, evens;
        for (int i=0; i<n; i++) {
            if (nums[i]&1)
                nums[i] *= 2;
            evens.insert(nums[i]);
        }

        int deviation = *(evens.rbegin()) - *(evens.begin());

        while (odds.empty() || (!evens.empty() && *(evens.rbegin()) > *(odds.rbegin()))) {
            int val = *(evens.rbegin());
            evens.erase(val);
            int newVal = val/2;
            if (newVal & 1) {
                odds.insert(newVal);
            } else {
                evens.insert(newVal);
            }

            int evenMin = evens.empty() ? INT_MAX : *(evens.begin()), evenMax = evens.empty() ? 0 : *(evens.rbegin());
            int oddMin = odds.empty() ? INT_MAX : *(odds.begin()), oddMax = odds.empty() ? 0 : *(odds.rbegin());
            deviation = min(deviation, max(oddMax, evenMax) - min(oddMin, evenMin));
        }

        return deviation;
    }
};