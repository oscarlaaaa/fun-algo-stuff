// 2023-02-08 (tabulation dp)
class Solution {
public:
    int jump(vector<int>& nums) {
        /*
            input: a list of int nums
            output: min num of jumps to reach the last index

            notes:
            - seems like simple tabulation dp
            - 2 for loops most likely?
                - one iterating forward and assigning min to each one
            - using a bool vector to hold values
            - wouldn't be greedy, right? i think greedy could work if we
              just want to see if its reachable but not for finding min
            
            analysis:
            - time = O(n^2) where n=length of nums
            - space = O(n) where n=length of nums
        */
        int n = nums.size();
        vector<int> minToReach(n, INT_MAX);
        minToReach[0] = 0;
        for (int i=0; i<n; i++) {
            if (minToReach[i] == INT_MAX)
                continue;
            for (int j=i+1; j<min(n, i+1+nums[i]); j++) {
                minToReach[j] = min(minToReach[j], minToReach[i]+1);
            }
        }
        return minToReach[n-1];
    }
};

// 2023-02-08 (optimized BFS)
class Solution {
public:
    int jump(vector<int>& nums) {
        /*
            input: a list of int nums
            output: min num of jumps to reach the last index

            approach:
            - initialize a queue for BFS, and a bool vector
                - queue will hold pairs of <position, # jumps>
            - perform BFS, and only queue up the values we haven't reached
              yet
                - because we do BFS, we'll never re-visit a position with a
                  lower number of steps than what was visited before. thus, we
                  only visit each node once
            - whenever we visit a new node, mark it as visited and queue it up
              with the current # of jumps+1
            - return when we reach the position n-1
            
            analysis:
            - time = O(n) where n=length of nums
            - space = O(n) where n=length of nums
        */
        int n = nums.size();
        deque<pair<int, int>> queue = {{0, 0}};
        vector<bool> reachable(n);
        reachable[0] = true;
        while (!queue.empty()) {
            auto [pos, jumps] = queue.front();
            queue.pop_front();

            if (pos == n-1)
                return jumps;
            
            for (int i=pos+1; i<=min(n-1, pos+nums[pos]); i++) {
                if (!reachable[i]) {
                    reachable[i] = true;
                    queue.push_back({i, jumps+1});
                }
            }
        }
        return -1;
    }
};

// 2023-02-08 (optimized)
class Solution {
public:
    int jump(vector<int>& nums) {
        /*
            input: a list of int nums
            output: min num of jumps to reach the last index

            approach:
            - greedy approach where we try to reach the farthest
              position each time
            - we iterate forward only to see if there is another 
              node reachable that can take us farther, and if so then
              we take that node's position next
            - however, if we can already reach the end from our current
              position, then we jump straight there
            
            analysis:
            - time = O(n) where n=length of nums
            - space = O(1) where n=length of nums
        */
        int n = nums.size();
        int pos = 0, jumps = 0;
        while (pos < n-1) {
            int farthest = min(pos+nums[pos], n-1);
            if (farthest == n-1) {
                pos = n-1;
            } else {
                for (int i=pos+1; i<=min(n-1, pos+nums[pos]); i++) {
                    if (nums[i]+i > nums[farthest]+farthest)
                        farthest = i;
                }
                pos = farthest;
            }
            jumps++;
        }
        return jumps;
    }
};