// 2023-10-31 (bits)
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        /*
        notes:
        - just slowly build up a vector starting from 0?
        - xor = when they're not matching
        - we can get the current build-up by tracking and xoring each value we add
          to our output
        - we can get each output by xoring our current recorded val by the next val in pref
          since a ^ b = c also means a ^ c = b
        
        normal:
        101 ^ 111 = 010
        010 ^ 010 = 000
        000 ^ 011 = 011
        011 ^ 010 = 001

        buildup:
        101 ^ 010 = 111
        010 ^ 000 = 010
        000 ^ 011 = 011
        011 ^ 001 = 010

        analysis:
        - time = O(n)
        - space = O(1) if u dont count output
        */
        int cur = pref[0];
        vector<int> output = {pref[0]};
        for (int i=1; i<pref.size(); i++) {
            int val = cur ^ pref[i];
            cur ^= val;
            output.push_back(val);
        }
        return output;
    }
};