// 2022-09-22 (iterative DP)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> check = vector<vector<int>>(n+1, vector<int>(m+1));
        
        int maxLength = 0;
        for (int i=1; i<n+1; i++) {
            for (int j=1; j<m+1; j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    check[i][j] = check[i-1][j-1]+1;
                    maxLength = max(maxLength, check[i][j]);
                }
            }
        }
        
        return maxLength;
    }
};