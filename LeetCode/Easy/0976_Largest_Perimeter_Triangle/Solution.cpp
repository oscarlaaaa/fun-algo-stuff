// 2022-10-12
class Solution {  
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=nums.size()-1; i>=2; i--) {
            // if the larger edge (hypotenuse) is greater than the sum of the 
            // other edges, then the triangle would have area 0 (it would be
            // a flat line)
            if (nums[i] >= nums[i-1]+nums[i-2])
                continue;
            return nums[i] + nums[i-1] + nums[i-2];
        }
        return 0;
    }
};