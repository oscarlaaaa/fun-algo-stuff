// 2022-07-04 (Bottom-up DP approach)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // first is if prior element is >, second is if prior is <
        vector<pair<int, int>> wiggle(nums.size(), {1, 1});
        int maxLength = 1;
        
        for (int i=0; i<wiggle.size(); i++) {
            for (int j=i+1; j<wiggle.size(); j++) {
                if (nums[i] > nums[j])
                    wiggle[j].first = max(wiggle[j].first, wiggle[i].second+1);
                if (nums[i] < nums[j])
                    wiggle[j].second = max(wiggle[j].second, wiggle[i].first+1);
                
                maxLength = max(maxLength, max(wiggle[j].first, wiggle[j].second));
            }
        }
        
        return maxLength;
    }
};

// 2022-07-04 (disgusting O(n) approach)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // represents the longest wiggle ending in a move towards which direction
        int up = 1, down = 1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                up = down+1;
            } else if (nums[i] < nums[i-1]) {
                down = up+1;
            } 
        }
        
        return max(up, down);
    }
};