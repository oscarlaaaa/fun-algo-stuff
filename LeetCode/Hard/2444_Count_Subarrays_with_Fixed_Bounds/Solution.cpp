// 2023-03-15 (sliding window)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        /*
            input: a list of ints and two integers mink/maxk
            output: the number of fixed bound subarrays matching the bounds

            notes:
            - looks like sliding window-ish?
            - start from left, and expand until we reach our possible bounds?
            - maybe we can streamline this through finding occurrences of minK and maxK,
              checking if there are any values between them with a lower/greater val?
                - we can potentially segment the array as well
            - count how many values in bounds min are to the left/right of min values, and
              vice versa for max values?
            - maybe collect values until we encounter a bound, then record how many elements
              within the bounds were before
                - maybe a stack! and pop values off?
            - important would be to have alternating; 11115 is still the same as 1xxx5;
                - every time we alternate, every iteration within bounds will be +1 subarray
                    - ex. 1515xxx = 9 vs 15xxx1 
            - also need to track how many vals before we hit a bounds number
                - start at 1; multiply by our factor once we hit a non-bound
            - maybe getting subarrays where the min/max is within the bounds, and iterating 2
              times total: 1 for min to max subarrays and 1 for max to min subarrays l-to-r
            
            approach:
            - generate all subarrays within our fixed bounds
            - process each subarray individually:
                - track the number of unmatched min/maxK values, as well as total matches
                    - total matches represents valid starting points
                - once we've encountered a min/maxK, add the opposite starting values into
                  our valid starting points
                - keep track of non min/maxK values as potential starting points
                    - whenever we've created a match, all potential starting points BEFORE our last
                      opposite bound (minK if we've hit a maxK and vice-versa) are only valid for the
                      next opposite match (if we hit minK again if we've just hit maxK and vice-versa)
                      so shift the queue forward
                    - if we hit the same bound twice, all values between the 2 bounds will be valid as
                      long as we get a match so we can just add them directly into our lower/upper start
                      count
            - overall, just find all valid starting points with matched min/max pairs as we iterate
            
            analysis:
            - time = O(n) where n=length of nums
            - space = O(n) where n=length of nums (but could be O(1) if i didn't pre-process)
        */
        int n = nums.size();
        vector<pair<int, int>> subarrays;
        
        // generate subarrays within the fixed bounds
        for (int start=0, end=0; end<=n; end++) {
            if (end == n) {
                subarrays.push_back({start, end});
            } else if (nums[end] < minK || nums[end] > maxK) {
                if (start != end) 
                    subarrays.push_back({start, end});
                start = end+1;
            }
        }

        long long output = 0;
        for (auto [start, end] : subarrays) {
            // unmatched minK and maxK counts
            int lowStarts = 0, highStarts = 0;

            // non-bound values that could potentially be a starting position
            int possibleStart1 = 0, possibleStart2 = 0;

            // number of valid starting positions
            int validStarts = 0;

            for (int i=start; i<end; i++) {
                // catch edge case of minK==maxK
                if (nums[i] == minK && nums[i] == maxK) {
                    validStarts++;
                } else {
                    if (nums[i] == minK) {
                        lowStarts++;
                        // all previous highstarts can be matched so convert into validStarts
                        validStarts += highStarts; 

                        // if we've matched something, then move our possible starts up the queue
                        if (highStarts > 0) {
                            validStarts += possibleStart1;
                            possibleStart1 = possibleStart2;
                            possibleStart2 = 0;
                        } else {
                            // if we've not matched anything, then all of our possible starts will
                            // be valid starts as soon as we match so convert into lowstarts
                            lowStarts += possibleStart2;
                            possibleStart2 = 0;
                        }
                        
                        highStarts = 0;
                    }
                    if (nums[i] == maxK) {
                        highStarts++;
                        // all previous lowstarts can be matched so convert into validStarts
                        validStarts += lowStarts;
                        
                        // if we've matched something, then move our possible starts up the queue
                        if (lowStarts > 0) {
                            validStarts += possibleStart1;
                            possibleStart1 = possibleStart2;
                            possibleStart2 = 0;
                        } else {
                            // if we've not matched anything, then all of our possible starts will
                            // be valid starts as soon as we match so convert into lowstarts
                            highStarts += possibleStart2;
                            possibleStart2 = 0;
                        }
                        
                        lowStarts = 0;
                    }
                }
                
                // queue up possible starting positions
                if (nums[i] != minK && nums[i] != maxK)
                    possibleStart2++;
                
                output += validStarts;
            }
        }
        
        return output;
    }
};