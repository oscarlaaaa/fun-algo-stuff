// 2022-06-09
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        
        while (numbers[left] + numbers[right] != target) {
            int sum = numbers[left] + numbers[right];
            if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        
        return {left+1, right+1};
    }
};