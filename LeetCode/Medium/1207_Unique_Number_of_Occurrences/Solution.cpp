// 2022-11-29
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int a : arr) {
            if (!counts.count(a))
                counts[a] = 0;
            counts[a]++;
        }
        vector<bool> seen(arr.size());
        for (auto itr=counts.begin(); itr!=counts.end(); ++itr) {
            auto [k, v] = *itr;
            if (seen[v]) return false;
            seen[v] = true;
        }
        return true;
    }
};