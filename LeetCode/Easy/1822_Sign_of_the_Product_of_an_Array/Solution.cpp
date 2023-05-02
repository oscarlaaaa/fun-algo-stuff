// 2023-05-01
class Solution {
public:
    int arraySign(vector<int>& nums) {
        /*
        notes:
        - count the number of negative signs
            - if we have an odd number, we'd return -1
            - otherwise, return 1
        - however, if we have a 0 anywhere, return 0 instead

        analysis:
        - time = O(n) where n=length of nums
        - space = O(1)
        */
        int oddCount = 0;
        for (int num : nums) {
            if (num == 0) return 0;
            if (num < 0) 
                oddCount++;
        }
        return oddCount & 1 ? -1 : 1;
    }   
};