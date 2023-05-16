// 2023-05-16
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        /*
        notes:
        - the number of operations is just the number of unique non-zero values
            - this is because each selection is subtracted from all numbers, and
              thus you'd need to do a subtraction from every unique number to hit 0

        analysis:
        - time = O(n) where n=length of nums
        - space = O(n) where n=length of nums
        */
        unordered_set<int> unique({0});
        for (int num : nums)
            unique.insert(num);
        return unique.size()-1;
    }
};