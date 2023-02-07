// 2023-02-07 (monotonic stack)
class Solution {
public:
    int maxArea(vector<int>& height) {
        /* 
            input: list of int heights of walls
            output: maximum amount of water we can store

            notes:
            - probably storing (x, height) pairs?
            - probably want a stack from small to large
                - don't care about large to small because there's 0 ways that a
                  smaller wall on the right can hold more than a larger wall on the left
            - stack from both ends?
                - if we try to find every combo, then we need O(n^2) which sucks big pp
                - some logic for how we pop off from each stack? kinda janky tho
                    - fuck it we ball
            
            analysis:
            - time = O(n) where n=length of height
            - space = O(n) where n=length of height
        */
        int n = height.size();
        vector<pair<int, int>> leftToRight, rightToLeft;
        for (int i=0; i<n; i++) {
            if (leftToRight.empty() || leftToRight.back().second < height[i])
                leftToRight.push_back({i, height[i]});
            if (rightToLeft.empty() || rightToLeft.back().second < height[n-1-i])
                rightToLeft.push_back({n-1-i, height[n-1-i]});
        }

        int mostWater = 0;
        while (!leftToRight.empty() && !rightToLeft.empty()) {
            auto [leftX, leftHeight] = leftToRight.back();
            auto [rightX, rightHeight] = rightToLeft.back();
            int volume = (rightX - leftX)*min(leftHeight, rightHeight);
            mostWater = max(mostWater, volume);
            if (leftToRight.size() > 1 && rightToLeft.size() > 1) {
                if (leftToRight[leftToRight.size()-2].second > rightToLeft[rightToLeft.size()-2].second) {
                    leftToRight.pop_back();
                } else {
                    rightToLeft.pop_back();
                }
            } else {
                if (leftToRight.size() > rightToLeft.size())
                    leftToRight.pop_back();
                else
                    rightToLeft.pop_back();
            }
        }
        return mostWater;
    }
};

// 2023-02-07 (optimal greedy)
class Solution {
public:
    int maxArea(vector<int>& height) {
        /* 
            input: list of int heights of walls
            output: maximum amount of water we can store

            notes:
            - greedy ass optimal approach
            - start with the widest, and the logic is that we need to
              increase the height in order to support more water, thus we
              always increment the side with the shorter wall
            - if they're equal, then it doesn't matter which one we move closer
              to the middle? not quite sure why
            
            analysis:
            - time = O(n) where n=length of height
            - space = O(1) where n=length of height
        */
        int n = height.size(), mostWater = 0;
        int l = 0, r = n-1;
        while (l < r) {
            mostWater = max(mostWater, (r-l)*min(height[r], height[l]));
            if (height[r] < height[l]) {
                r--;
            } else {
                l++;
            }
        }   
        return mostWater;
    }
};