// 2022-09-13 (monotonic stack)
//
// maintain a stack of temperatures (monotonic)
// - if encounter a higher temp, pop off from stack all temps < current
// - add onto stack afterwards
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> nextWarmer(temperatures.size(), 0);
        deque<int> stack;
        
        for (int i=0; i<temperatures.size(); i++) {
            while (stack.size() > 0 && temperatures[stack.back()] < temperatures[i]) {
                nextWarmer[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        
        return nextWarmer;
    }
};