// 2023-05-13 (tabulation dp)
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        /*
        notes:
        - draw connecting lines between nums1 and nums2 where the line does not
          intersect with other lines
        - looks like a stack-style kinda question? maybe queue up one side as a
          stack?
        - or maybe it's just seeing the longest subsequence that can be matched
          on both sides
            - would this be dp? maybe using a m+1 x n+1 grid
            - initialize all to 0, and run through the grid from [1, m] and [1, n]
            - cur position = max of [i-1][j] and [i][j-1]
            - if letters at [i-1][j-1] match, then grab val from [i-1][j-1]+1 from grid
        
        x  2  5  1  2  5
       10  0  0  0  0  0  0
        5  0  1  1  1  1  1
        2  1  1  1  2  2  2
        1  1  1  2  2  2  2
        5  1  2  2  2  3  3
        2  1  2  2  3  3  3
           0  0  0  0  0  0

        analysis:
        - time = O(mn) where m=length of nums1 and n=length of nums2
        - space = O(mn) where m=length of nums1 and n=length of nums2
        */
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> maxLines(m+1, vector<int>(n+1));
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                maxLines[i][j] = std::max(maxLines[i][j], max(maxLines[i-1][j], maxLines[i][j-1]));
                if (nums1[i-1] == nums2[j-1])
                    maxLines[i][j] = std::max(maxLines[i][j], maxLines[i-1][j-1]+1);
            }
        }
        return maxLines[m][n];
    }
};