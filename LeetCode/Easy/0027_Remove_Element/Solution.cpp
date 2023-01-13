// 2023-01-13 (two pointer)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*
            input: a list of int nums, and an int val to remove
            output: k for the k slots that were not removed

            approach:
            - looks like it'd be in-place swapping
            - 2 pointer, where right pointer moves left until it's at a non-val, and left pointer
              moves right until its at a val
            - swap the 2 values, and increment our K counter
            - return K at the end

            analysis:
            - time = O(n) where n=num of elements
            - space = O(1)
        */
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            if (nums[left] != val) {
                left++;
            } else if (nums[right] == val) {
                right--;
            } else {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }
        return left;
    }
};