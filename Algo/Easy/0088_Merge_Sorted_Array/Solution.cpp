// 2022-06-08
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ordered;
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < m && ptr2 < n) {
            ordered.push_back(nums1[ptr1] < nums2[ptr2] ? nums1[ptr1] : nums2[ptr2]);
            if (nums1[ptr1] < nums2[ptr2]) ptr1++;
            else ptr2++;
        }
        while (ptr1 < m) {
            ordered.push_back(nums1[ptr1]);
            ptr1++;
        }
        while (ptr2 < n) {
            ordered.push_back(nums2[ptr2]);
            ptr2++;
        }
        
        for (int i=0; i<m+n; i++) {
            nums1[i] = ordered[i];
        }
    }
};