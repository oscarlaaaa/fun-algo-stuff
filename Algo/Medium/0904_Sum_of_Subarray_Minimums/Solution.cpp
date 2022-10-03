// 2022-10-02 (monotonic stack)
//
// The approach to this question that I took was to utilize a stack, and find some sort of 
// logic I could apply at each iteration to reduce the required time complexity. I ended up
// using a monotonic stack that goes from smallest to largest and seeing how many subarrays
// a value would affect if it were smaller than a previous value. I found out through some trial
// and error that if I calculated the sum of subarray mins from my previously encountered values
// and if a value is smaller than a previous value, it would affect the sum by 
// (current value - previous value) * (array size - current index) * (previous index - previous previous index) for every
// stacked value before it.
//
// This logic is predicated upon the fact that at each index, there are (array length - current index) subarrays
// that include the current value and exclude all values before it. Thus, we can assume at each step that the current value
// will be the current minimum for (length - index) subarrays, and trust that future smaller values will retroactively
// fix our total with the above logic.

// An example is shown below (note that each value has (length - index) subarrays that exclude all previous values):
//
// arr = [3,4,1,2]
// [3] [3,4] [3,4,1] [3,4,1,2]     - (1-3)*(4-2)*(1-0) = -4
// [4] [4,1] [4,1,2]               - (1-4)*(4-2)*(2-1) = -6
// [1] [1,2]     <-------- 1 is smaller than all of the values, so it would impact our running total by  
// [2]                     
// 
// by keeping this running tally, I can effectively adjust my running total based on whatever new values
// I encounter and retroactively removing + adding to my sum as I progress.
//
class Solution {
public:
    #define ll long long
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        ll total = 0;
        deque<int> minimums; // tracks elements from low to high, stores their indices
        for (int i=0; i<n; i++) {
            int numAffect = n-i;
            int lowestPop = i;
            while (!minimums.empty() && arr[i] < arr[minimums.back()]) {
                int lastIdx = minimums.back();
                minimums.pop_back();
                int lastLastIdx = minimums.empty() ? -1 : minimums.back();

                // retroactively adjust running total
                total = (total + 1LL*(arr[i] - arr[lastIdx])*numAffect*(lastIdx-lastLastIdx));
            }
            // record as if current value is the minimum for (length - index) subarrays
            total += 1LL*arr[i]*numAffect;
            minimums.push_back(i);
        }
        return (int) (total % 1000000007);
    }
};