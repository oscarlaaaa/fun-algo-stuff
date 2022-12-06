// 2022-11-26 (prefix-suffix approach)
/*
    If we close a shop at a specific point, that would mean we will receive
    all of the penalties from before we've closed (i.e. customers[i] == 'N') while
    also receiving all of the penalties from after we've closed (i.e. customers[i] == 'Y').

    As such, we can approach this by calculating a running count of penalties left-to-right 
    if we were open, and then calculating a running count of penalties right-to-left. We can
    then calculate the penalty of closing at a specific time by adding the penalties from
    openPenalty[i] and closePenalty[i+1]. We then just take the closePenalty index of the 
    index with the lowest penalty sum.
*/
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> openPenalty(n, 0), closePenalty(n, 0);
        
        // running sum of penalties while open
        for (int i=0; i<n; i++) {
            if (customers[i] == 'N') openPenalty[i]++;
            if (i < n-1) openPenalty[i+1] += openPenalty[i];
        }
        
        // running sum of penalties while closed
        for (int i=n-1; i>=0; i--) {
            if (customers[i] == 'Y') closePenalty[i]++;
            if (i >= 1) closePenalty[i-1] += closePenalty[i];
        }
        
        int idx = 0, least = n;
        for (int i=-1; i<n; i++) {
            int pen = 0;
            if (i >= 0)
                pen += openPenalty[i];
            if (i < n-1) 
                pen += closePenalty[i+1];
            if (pen < least) {
                least = pen;
                idx = i+1;
            }
        }
        return idx;
    }
};