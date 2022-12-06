// 2022-09-17 (Sort + 2pointer)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end(), [&](const int& x, const int& y) {
            return x < y;
        });
        int n = changed.size();
        
        vector<int> originalArray;
        vector<bool> visited = vector<bool>(n, false);
        int orig = 0, doub = 1;
        while (orig < n) {
            while (orig < n && visited[orig]) 
                orig++;
            visited[orig] = true;
            
            while (doub < n && (visited[doub] || changed[doub] < changed[orig]*2)) 
                doub++;
            visited[doub] = true;
            
            // this means we've visted every value, so break out of the loop
            if (orig == n && doub == n) break;
            
            // if our left pointer doesn't have a double, then this isn't a doubled array
            if (doub >= n || changed[doub] > changed[orig]*2)
                return {};
            
            originalArray.push_back(changed[orig]);
        }
        
        return originalArray;
    }
};