class Solution {
public:
    double convertIntoKey(int xDiff, int yDiff) {
        if (yDiff == 0)
            return 100000.0;
        return 1.0*xDiff/yDiff;
    }
    int maxPoints(vector<vector<int>>& points) {
        /*
            input: a list of points on an x-y plane
            output: the max number of points that lie on the same straight line

            notes:
            - only up to 300 points, so could probably do an inefficent approach
            - maybe organize points into groups where the difference between x-y coords is the same?
            - maybe just try an O(n^2) solution?

            approach:
            - doubly nested for loop
            - first one to select a point to compare other points to
            - second loop checks all points (except current)
                - initialize an unordered set of ratios between x-diff and y-diff
                - same ratio = along the same plane, so we can add to the count
            - keep track of the largest count of a specific ratio for each point, and return
                the largest we find
        */
        int n = points.size(), maxNumPoints = 0;
        for (int i=0; i<n; i++) {
            unordered_map<double, int> lineCounts;
            for (int j=0; j<n; j++) {
                if (i == j) 
                    continue;
                
                double key = convertIntoKey(points[i][0]-points[j][0], points[i][1]-points[j][1]);
                lineCounts[key]++;
                maxNumPoints = max(maxNumPoints, lineCounts[key]);
            }
        }
        return maxNumPoints+1;
    }
};