// 2023-03-21 (greedy)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        /*
        input: list of nums
        output: the number of subarrays of only zeroes

        notes:
        - because we only care about continuous portions (subarrays),
          we can find a pattern in how many subarrays a single sequence
          of zeroes would have
            - 0         = 1
            - 00 = 3    = 1 + 2
            - 000 = 6   = 1 + 2 + 3
            - 0000 = 10 = 1 + 2 + 3 + 4
        - can reason that the number of subarrays would just be the summation
          of the current count of zeroes
        - thus we just need to iterate and count the number of zeroes we have while
          adding our count to our output at each step
        
        analysis:
        - time = O(n) where n=length of nums
        - space = O(1) 
        */
        long long output = 0;
        int count = 0;
        for (int num : nums) {
            if (num == 0) {
                count++;
            } else {
                count = 0;
            }
            output += count;
        }
        return output;
    }
};