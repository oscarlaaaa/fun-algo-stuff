class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        /*
        input: vector of ints
        output: vector of ints where each element is the greatest element to its right

        notes:
        - from expected output, only increases from right to left
        - starts off at -1 if nothing to its right

        approach:
        - keep track of an int greatestElement that starts at -1
        - iterate from right to left
            - hold the current element
            - replace current element with greatest
            - assign maximum of current greatest and hold to current greatest
        - return input arr
        */

        int curGreatest = -1;
        for (auto itr=arr.rbegin(); itr != arr.rend(); ++itr) {
            int hold = *itr;
            *itr = curGreatest;
            curGreatest = max(curGreatest, hold);
        }
        return arr;
    }
};