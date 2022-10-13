// 2022-10-13 (mono stack)
/*
PLAN:
    - increasing monotonic stack
    - every rectangle we encounter, calculate the length * width
        of rectangle using current idx and top stack val
    - if we encounter a smaller value, calculate the widest rectangle
        possible and pop off the stack until top of stack is >= current
    - assign the index of the current val we put onto the stack as
        either itself or the last value we were able to pop off (if a lower
        value was able to pop off prior values, that means the prior values
        were greater and thus we can think of the last popped value as the
        leftmost idx that the current height starts at)
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> h, w; // h=heights, w=indices
        int maxArea = 0;
        for (int i=0; i<n; i++) {       
            int lastPopped = i;

            // pop off and calculate height
            while (!h.empty() && h.back() > heights[i]) {
                int height = h.back();
                int width = i - w.back();
                maxArea = max(maxArea, height*width);
                lastPopped = w.back();
                h.pop_back(); w.pop_back();
            }
            // only add if height isn't at 0
            if (heights[i] > 0) {
                h.push_back(heights[i]);
                w.push_back(lastPopped);
            }
        }

        // pop off any remaining values within our stacks
        while (!h.empty()) {
            int height = h.back();
            int width = n - w.back();
            maxArea = max(maxArea, height*width);
            h.pop_back(); w.pop_back();
        }
        return maxArea;
    }
};