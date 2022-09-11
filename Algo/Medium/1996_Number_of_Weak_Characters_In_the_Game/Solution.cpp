
// 2022-09-10 (sort and conquer)
//
// Because we want to introduce some ordering to our input, we sort it by one parameter, then the other
// to be able to approach the solution more simply. After sorting, we can establish that any characters
// that are earlier + have lower attack will be weak if there exists a character in front of them with
// greater attack (which is simple to establish if we sort first) and greater defense (which we can keep
// track of as we iterate backwards).
//
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        
        int weakCharacters = 0;
        int idx = properties.size()-1;
        int curMaxDef = 0;
        while (idx >= 0) {
            int curAtt = properties[idx][0];
            int curDef = properties[idx][1];
            
            while (idx >= 0 && curAtt == properties[idx][0]) {
                if (curMaxDef > properties[idx][1])
                    weakCharacters++;
                idx--;
            }
            
            curMaxDef = max(curMaxDef, curDef);
        }
        
        return weakCharacters;
    }
};