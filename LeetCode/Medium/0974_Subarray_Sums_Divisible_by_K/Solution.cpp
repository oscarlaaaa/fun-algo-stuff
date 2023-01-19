// 2023-01-18
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        /*
            input: list of ints and an int k
            output: the number of subarrays with a sum divisible by k

            notes:
            - is this dp?
            - preprocess by dividing everything by k?
            - cum sum, and storing the sum%k into a dict?
                - basically if you want a sunarray be divisible, there needs to be a
                  cum sum value before your current position that allows you to
                  hit 0 (meaning you're divisble by k)
            - the idea is that a cumulative sum of 5 from 0 to x will turn into a cumulative
              sum of 3 if you subtract a cumulative sum of 2 from 0 to y from it
            - thus, our goal is to see how many cumulative sums we've encountered before match
              our current cumulative sum, as subtracting it will allow us to hit a remainder of
              0 which means our subarray is divisible by k
                - we do sum%k before checking + storing to minimize the effort in checking
            
            approach:
            - create a vector of size k
            - iterate through nums, keeping track of cumulative sum
            - number of subarray sums = count of previous sums with curSum%k
                - add to a total
            - increment curSum%k by 1
            - return the total

            notes:
            - time = O(n) where n = length of nums, although modulus is $$$
            - space = O(k)
        */
        vector<int> cumSums(k);
        cumSums[0]++;
        int subarrays = 0;
        int n = nums.size(), total = 0;
        for (int i=0; i<n; i++) {
            total += nums[i];
            int remainder = (total%k+k)%k; // you can get negative values without this even if ugly
            subarrays += cumSums[remainder];
            cumSums[remainder]++;
        }
        return subarrays;
    }
};