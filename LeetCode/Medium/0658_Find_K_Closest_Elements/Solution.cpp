// 2022-09-29 (two-pointer)
//
// Rather than starting from the value X and going outwards, it's faster
// to start from the outside and go inwards whilst eliminating the values
// that would not be included in the end output.
// 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1;
        while (r - l >= k) {
            int diffL = abs(arr[l] - x), diffR = abs(arr[r] - x);
            if (diffL < diffR || (diffL == diffR && arr[l] < arr[r])) {
                r--;
            } else {
                l++;
            }
        }
        return vector<int>(arr.begin()+l, arr.begin()+r+1);
    }
};