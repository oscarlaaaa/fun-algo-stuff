// 2023-06-05
class Solution {
public:
    double getSlope(vector<int>& pointA, vector<int>& pointB) {
        return 1.0*(pointA[0]-pointB[0]) / (pointA[1]-pointB[1]);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        /*
        notes:
        - we just want to establish a slope and check that every point
          exists along the line of that slope
        - probably take first and last points to create scope, then 
          check if every other point with the first point creates the same
          slope

        analysis:
        - time = O(n) where n=length of coordinates
        - space = O(1)
        */
        int n = coordinates.size();
        if (coordinates[0][0] > coordinates[1][0])
            std::swap(coordinates[0], coordinates[1]);

        double slope = getSlope(coordinates[0], coordinates[1]);
        for (int i=2; i<n; i++) {
            if (coordinates[i-1][0] > coordinates[i][0])
                std::swap(coordinates[i-1], coordinates[i]);
            double checkSlope = getSlope(coordinates[i-1], coordinates[i]);
            if (checkSlope != slope)
                return false;
        }
        return true;
    }
};