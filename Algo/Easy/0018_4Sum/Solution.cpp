// 2022-05-27 (sorting + double loop + 2sum unoptimized (only 1/5 didn't TLE heh))
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sums;
        int a = 0;
        while (a < nums.size()) {
            int b = a+1;
            while (b < nums.size()) {
                
                unordered_set<long> need;
                int newTarget = target - nums[a] - nums[b];
                int c = b+1;
                while (c < nums.size()) {
                    if (need.count(nums[c])) {
                        sums.push_back({nums[a], nums[b], nums[c], newTarget-nums[c]});
                        int cur = nums[c];
                        while (c < nums.size() && nums[c] == cur) c++;
                    } else {
                        if (newTarget > 0) {
                            if (newTarget + INT_MIN <= nums[c])
                                need.insert(newTarget - nums[c]);
                        } else {
                            if (newTarget + INT_MAX >= nums[c])
                                need.insert(newTarget - nums[c]);
                        }
                        c++;
                    }
                }
                
                int cur = nums[b];
                while (b < nums.size() && nums[b] == cur) b++;
            }
            int cur = nums[a];
            while (a < nums.size() && nums[a] == cur) a++;
        }
        return sums;
    }
};

// 2022-05-27 (sorting + double loop + 2sum solution optimized)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sums;
        int size = nums.size();
        
        for (int a = 0; a < size-3; a++) {
            // allows us to skip useless loops - integral
            if ((long) nums[a] + nums[a+1] + nums[a+2] + nums[a+3] > target) break;
            if ((long) nums[a] + nums[size-1] + nums[size-2] + nums[size-3] < target) continue;
            
            for (int b = a+1; b < size-2; b++) {
                // same with these heh
                if ((long) nums[a] + nums[b] + nums[b+1] + nums[b+2] > target) break;
                if ((long) nums[a] + nums[b] + nums[size-1] + nums[size-2] < target) continue;
                
                unordered_set<long> need;
                int newTarget = target - nums[a] - nums[b];
                
                for (int c = b+1; c < size; c++) {
                    if (need.count(nums[c])) {
                        sums.push_back({nums[a], nums[b], nums[c], newTarget-nums[c]});
                        while (c+1 < size && nums[c] == nums[c+1]) c++; // skip dupes
                    } else {
                        // overflow check
                        if (newTarget >= 0 && newTarget + INT_MIN <= nums[c] || 
                           newTarget <= 0 && newTarget + INT_MAX >= nums[c]) 
                                need.insert(newTarget - nums[c]);
                    }
                }
                while (b < size-2 && nums[b] == nums[b+1]) b++; // skip dupes
            }
            while (a < size-3 && nums[a] == nums[a+1]) a++; // skip dupes
        }
        return sums;
    }
};