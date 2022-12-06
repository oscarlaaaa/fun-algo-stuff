/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

// 2022-11-15 (binary search)
class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (guess(mid) > 0) {
                l = mid+1;
            } else if (guess(mid) < 0) {
                r = mid;
            } else {
                return mid;
            }
        }
        return -1;
    }
};