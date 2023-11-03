// 2023-11-03 (huh)
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        /*
        notes:
        - i'm so confused; isn't this just itertae from 1 to however many we need to hit our target?
        - can't we just iterate thru and push+pop as we need?? huh?

        analysis:
        - time = O(m) where m=length of target
        - space = O(1) if we don't count output
        */
        int m = target.size();
        vector<string> output;
        for (int i=0; i<m; i++) {
            int prev = i > 0 ? target[i-1] : 0;
            int diff = target[i] - prev;
            output.push_back("Push");
            for (int j=0; j<diff-1; j++) {
                output.push_back("Pop");
                output.push_back("Push");
            }
        }
        return output;
    }
};
