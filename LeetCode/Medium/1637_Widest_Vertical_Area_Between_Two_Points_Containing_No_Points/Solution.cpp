// 2023-12-22 (sorting)
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        /*
        notes:
        - isn't this just the greatest difference in x? wtf
        - sort and then greatest diff

        analysis:
        - time = O(nlogn)
        - space = O(1)
        */
        std::sort(points.begin(), points.end(), [](std::vector<int>& a, std::vector<int>& b) {
            return a[0] < b[0];
        });

        int n = points.size();
        int greatestWidth = 0;
        for (int i=0; i<n-1; i++) {
            greatestWidth = std::max(greatestWidth, points[i+1][0]-points[i][0]);
        }
        return greatestWidth;
    }
};