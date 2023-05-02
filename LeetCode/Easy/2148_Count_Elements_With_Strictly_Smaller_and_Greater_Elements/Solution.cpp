// 2023-05-01
class Solution {
public:
    int countElements(vector<int>& nums) {
        /*
        notes:
        - keep track of min and max elements in the list
        - every time we find a num less than max but greater than min, we can
          increment a count to return later

        analysis:
        - time = O(n) where n=length of nums
        - space = O(1)
        */
        int count = 0;
        int lowest = nums[0], highest = nums[0];
        for (int num : nums) {
            lowest = min(lowest, num);
            highest = max(highest, num);
        }
        for (int num : nums) {
            if (lowest < num && num < highest)
                count++;
        }
        return count;
    }
};