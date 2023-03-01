// 2023-03-01 (quicksort)
class Solution {
public:
    void myQuicksort(vector<int>& nums, int l, int r) {
        // only size of 1
        if (r-l <= 1)
            return;

        // choose the median of the first/mid/last values of nums to avoid worst-case scenario of
        // an already-sorted list
        int low = l, mid = l+(r-l-1)/2, high = r-1;
        vector<pair<int, int>> pivotCandidates = {{nums[low], low}, {nums[mid], mid}, {nums[high], high}};
        sort(pivotCandidates.begin(), pivotCandidates.end());
        nums[low] = pivotCandidates[1].first;
        nums[mid] = pivotCandidates[0].first;
        nums[high] = pivotCandidates[2].first;

        // we track the start/end of a section of pivot element occurrences to avoid worst-case scenario of
        // repeated values
        int pivotStart = low, pivotEnd = low;
        for (int i=l+1; i<r; i++) {
            if (nums[i] <= nums[pivotEnd]) {
                // swap smaller element with element in front of pivot group
                swap(nums[pivotEnd+1], nums[i]);
                
                // swap start of pivot group with element ahead of the group
                swap(nums[pivotStart], nums[pivotEnd+1]);

                pivotEnd++;
                // if start and end are equal, we don't need to increment start as that means we found another
                // pivot element
                if (nums[pivotEnd] != nums[pivotStart])
                    pivotStart++;
            }
        }
        
        // pivot group is in the right place, so ignore it and process the rest
        myQuicksort(nums, l, pivotStart);
        myQuicksort(nums, pivotEnd+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        /*
            input: a list of ints
            output: a sorted list of ints

            notes:
            - essentially implementation of a sorting algorithm without using built-in functions like sort
            - i think i could probably do mergesort? quicksort might b better tho for space
                - lets try going with quicksort
        */
        myQuicksort(nums, 0, nums.size());
        return nums;
    }
};