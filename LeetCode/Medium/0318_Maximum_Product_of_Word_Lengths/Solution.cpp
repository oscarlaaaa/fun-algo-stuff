// 2022-05-28
/**
 * We create bitsets for each word, and mark their respective bitset
 * with a 1 if they have that character (0 = 'a', 1 = 'b', etc)
 * 
 * We then loop through every pair combination of bitsets, and if they're
 * completely unique, then we can record down the product of sizes if it's
 * the current greatest maximum.
 * 
 * Time: O(n^2)
 * Space: O(n)
 * 
 */
class Solution {
public:
    bool uniqueStrings(bitset<26>& s1, bitset<26>& s2) {
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == 1 && s2[i] == 1) return false;
        }
        return true;
    }
    
    int maxProduct(vector<string>& words) {
        int maximum = 0;
        vector<bitset<26>> hasChars;
        for (int i = 0; i < words.size(); i++) {
            bitset<26> has;
            for (char c : words[i]) {
                has[c - 'a'] = 1;
            }
            hasChars.push_back(has);
        }
        
        for (int i = 0; i < hasChars.size(); i++) {
            for (int j = i+1; j < hasChars.size(); j++) {
                if (uniqueStrings(hasChars[i], hasChars[j])) {
                    int size = words[i].size() * words[j].size();
                    maximum = max(maximum, size);    
                }
            }
        }
        return maximum;
    }
};