// 2023-04-28 (binary search)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        /*
        notes:
        - looks like basically binary search?
        - probably binary search by comparing values
            - can use 3; if mid-1 > mid, then, then go left and vice versa
        - probably start from 1 and n-2 since the peak will always be in the middle

        analysis:
        - time = O(logn) where n=length of arr
        - space = O(1)
        */
        int left = 1, right = arr.size()-2;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (arr[mid] < arr[mid+1]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};