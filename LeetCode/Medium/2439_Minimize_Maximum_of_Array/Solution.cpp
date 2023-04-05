// 2023-04-05 (stack)
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        /*
        notes:
        - can choose any index and decrease it while adding 1 to the val
          behind it
        - kind of like flowing down from right to left
        - can average up from right to left until we hit a val > our average,
          which we then have a new starting spot to flow down from
            - we can iterate from left to right until we end up decreasing,
              then average it out?
            - stack of pairs of sums and counts?
            - just merge the groups together if current average is higher than
              the previous average (flow right-to-left)
        
        analysis:
        - time = O(n) where n=length of nums
        - space = O(n)
        */
        deque<pair<long long, int>> stack;
        for (int num : nums) {
            long long total = num;
            int count = 1;

            while (!stack.empty()) {
                auto [stackTotal, stackCount] = stack.back();
                if (total/count < stackTotal/stackCount) 
                    break;
                    
                total += stackTotal;
                count += stackCount;
                stack.pop_back();
            }
            stack.push_back({total, count});
        }

        int minMax = 0;
        while (!stack.empty()) {
            auto [stackTotal, stackCount] = stack.back();
            minMax = max(minMax, (int) ceil((1.0*stackTotal)/stackCount));
            stack.pop_back();
        }
        return minMax;
    }
};