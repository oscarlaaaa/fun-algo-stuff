// 2024-01-05
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        notes:
        - initial thought would be to do DP, but possibly slow
        - probably keep track of a list of numbers, and find the first number
          in the list less than the current number
           - if there's a number ahead of it, then replace it
           - if there's no number ahead of it, append it to end of list
        - can use binary search to get this down to O(nlogn)
          - set.lower_bound for this since it uses b-search and will find the
            first val >= the number
        
        analysis:
        - time = O(nlogn)
        - space = O(n);
        */
        std::set<int> subsequence;

        for (int num : nums) {
            auto itr = subsequence.lower_bound(num);
            // if this is not the largest number, replace whatever is in its spot
            if (itr != subsequence.end()) {
                subsequence.erase(*itr);
            } 
            subsequence.insert(num);
        }

        return subsequence.size();
    }
};