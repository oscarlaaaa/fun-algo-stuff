// 2022-11-18 (priority queue)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto coordCmp = [](const vector<int>& a, const vector<int>& b) {
            return sqrt(a[0]*a[0] + a[1]*a[1]) < sqrt(b[0]*b[0] + b[1]*b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(coordCmp)> closest(coordCmp);
        for (vector<int> point : points) {
            closest.push(point);
            if (closest.size() > k) closest.pop();
        }
        vector<vector<int>> output;
        while (!closest.empty()) {
            output.push_back(closest.top());
            closest.pop();
        }
        return output;
    }
};