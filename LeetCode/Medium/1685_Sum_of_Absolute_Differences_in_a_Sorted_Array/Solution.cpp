// 2023-11-25 (prefix/suffix sum)

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        /*
        notes:
        - this looks relatively easy probably?
        - can't each position just be the total value of everything - length*val?
            - nvm it's absolute val so you can't!!!!!
        - length too long to do brute force
        - the fact taht it's sorted would probably help? is there repeating vals? i think so
            - every val to the left will be 0 or negative, and to the right will be 0 or positive
        - maybe 2 passes
            - left to right we save arr1[i] = abs(summation of [0, i-1] - val[i]*i)
            - right to left we save arr2[i] = summation of [i+1, n) - val[i]*i
        - return sum of each spot

        analysis:
        - time = O(n)
        - space = O(1) if we don't include output
        */
        int n = nums.size();
        vector<int> differences(n);

        int preTotal = 0;
        for (int i=0; i<n; i++) {
            int diff = nums[i]*i - preTotal;
            differences[i] += diff;
            preTotal += nums[i];
        }

        int postTotal = 0;
        for (int i=n-1; i>=0; i--) {
            int diff = postTotal - nums[i]*(n-1-i);
            differences[i] += diff;
            postTotal += nums[i];
        }

        return differences;
    }
};
