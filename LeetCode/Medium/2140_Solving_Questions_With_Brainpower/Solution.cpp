// 2023-05-13 (tabulation dp)
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        /*
        notes:
        - looks like tabulative dp?
        - represent max points with a vector of length questions+1
        - check if previous position has greater max, and take if so
        - for each question, send cur points + points gained for doing
          the question to brainpower spaces ahead

        analysis:
        - time = O(n) where n=length of questions
        - space = O(n) where n=length of questions
        */
        int n = questions.size();
        vector<long long> maxPoints(n+1);
        for (int i=0; i<n; i++) {
            int pts = questions[i][0], bp = questions[i][1];

            if (i > 0)
                maxPoints[i] = std::max(maxPoints[i], maxPoints[i-1]);
            int nextSpot = std::min(i+bp+1, n);
            maxPoints[nextSpot] = std::max(maxPoints[nextSpot], maxPoints[i]+pts);
        }
        return maxPoints[n];
    }
};