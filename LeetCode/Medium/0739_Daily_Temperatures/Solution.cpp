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

// 2022-12-17 (monotonic stack)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
            input: list of ints temperatures where temp[i] = temp on ith day
            output: list of ints where output[i] = number of days you have to wait to get a warmer temp

            notes:
            - need to probably use a stack as we need to process prior, lower temps once a higher one is
              reached
                - monotonic stack most likely
            - last value of our output list is always 0 since it's the last one

            approach:
            - monotonic stack of decreasing temperatures (probably their indices)
            - initialize an output list of all 0s
            - if we encounter a temp that is greater then the top of our stack, we pop off our stack and
              assign the difference in indices to the output list
            - otherwise, we just add it onto the top of our stack
        */
        int n = temperatures.size();
        vector<int> output(n, 0);
        deque<int> stack;
        for (int i=0; i<n; i++) {
            while (!stack.empty() && temperatures[stack.back()] < temperatures[i]) {
                output[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return output;
    }
};