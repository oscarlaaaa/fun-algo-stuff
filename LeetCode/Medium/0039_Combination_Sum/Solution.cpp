// 2022-06-12
class Solution {
public:
    vector<vector<int>> combinations;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combo;
        findCombinations(candidates, 0, target, combo);
        return this->combinations;
    }
    
    void findCombinations(vector<int>& candidates, int idx, int target, vector<int>& combo) {
        if (target == 0) {
            auto comboCopy = combo;
            this->combinations.push_back(comboCopy);
            return;
        }
        
        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) 
                continue;
            
            combo.push_back(candidates[i]);
            findCombinations(candidates, i, target-candidates[i], combo);
            combo.pop_back();
        }
    }
};