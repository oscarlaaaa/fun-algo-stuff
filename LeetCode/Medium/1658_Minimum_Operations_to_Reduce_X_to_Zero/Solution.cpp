// 2022-06-10 (Prefix Sum approach)
/**
 * The prefix sum approach requires us to keep track of the prefix-sum going
 * from left-to-right, and vice-versa. Using one of the prefix sum lists, we
 * can subtract their sums from x to see what values we need to see in the other
 * prefix sum list. As we iterate through the second list, we remove any vals
 * that were created using the prefix sum of that index to prevent overlap.
 * 
 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if (nums.front() == x || nums.back() == x) return 1;
        int minimum = INT_MAX;
        vector<int> leftToRight = nums, rightToLeft = nums;
        
        int end = nums.size()-1;

        // create 2 prefix sum lists going in both directions
        for (int i=1; i<nums.size()-1; i++) {
            leftToRight[i] += leftToRight[i-1];
            rightToLeft[end-i] += rightToLeft[end-i+1];
            if (leftToRight[i] == x)
                minimum = min(minimum, i+1);
            if (rightToLeft[end-i] == x)
                minimum = min(minimum, i+1);
        }
        
        // establish what values we'd like to see in the second prefix sum list
        unordered_map<int, int> need;
        for (int i=0; i<nums.size(); i++) {
            if (leftToRight[i] > x) break;
            need[x - leftToRight[i]] = i+1;
        }
        
        for (int i=end; i>=0; i--) {
            need.erase(x - leftToRight[i]); // remove overlapping values
            if (need.count(rightToLeft[i])) 
                minimum = min(minimum, need[rightToLeft[i]] + (end - i + 1));
        }
        
        return minimum == INT_MAX ? -1 : minimum;
    }
};

// 2022-06-10 (Sliding window)
/**
 * Rather than focus on what to remove from either end, the sliding window approach
 * focuses on what to keep in the center. This way, we can simply keep track of a sliding
 * window of values to keep in order to represent the leftover array after removing x value
 * worth of nums, keep track of the widest window (i.e. most vals kept) we've encountered with 
 * x removed, and return the lowest value.
 * 
 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if (nums.front() == x || nums.back() == x) return 1;
        int minimum = INT_MAX, size = nums.size();
        int left = 0, right = 0, total = 0;
        
        for (int num : nums)
            total += num;
        
        if (total <= x) return total < x ? -1 : size;
        
        // how much we need to not remove from the original array
        // to result in x value removed from either end
        int needed = total - x;  
        int windowSum = 0;
        while (right < nums.size()) {
            while (right < nums.size() && windowSum < needed) 
                windowSum += nums[right++];
            
            while (left < right && windowSum >= needed) {
                if (total - windowSum == x)
                    minimum = min(minimum, size - (right - left));
                windowSum -= nums[left++];
            }
        }
        
        return minimum == INT_MAX ? -1 : minimum;
    }
};