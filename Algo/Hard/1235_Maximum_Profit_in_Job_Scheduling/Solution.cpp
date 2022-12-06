// 2022-12-05 (tabulation dp)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        /*
            input: start/endtimes + profits of jobs
            output: maximum possible profit from non-overlapping jobs

            notes:
            - start/endTime is super huge, so not possible to DP with a vector/array
            - need some way to carry maximum profit forwards

            approach:
            - group jobs by start times
            - sorted map of profits, where each key is a start/end time
                - assign all profit values to 0 to start off
            - iterate through the profit keys (sorted start+endtimes)
            - get the total profit at the current spot, and iterate thru the jobs that start at this time
                - assign cur profit + job's profit to the end time if it's greater than what's there
            - if we're not at the end, move our current profit forward if greater than the next time's profit
            - return the last value in the map.
        */
        unordered_map<int, vector<pair<int, int>>> jobs;
        map<int, int> maxProfit;
        for (int i=0; i<startTime.size(); i++) {
            jobs[startTime[i]].push_back({endTime[i], profit[i]});

            if (!maxProfit.count(startTime[i])) 
                maxProfit[startTime[i]] = 0;
            if (!maxProfit.count(endTime[i])) 
                maxProfit[endTime[i]] = 0;
        }

        for (auto itr=maxProfit.begin(); itr != maxProfit.end(); itr++) {
            auto &[time, tot] = *itr;
            for (auto& [end, prof] : jobs[time]) {
                maxProfit[end] = max(maxProfit[end], tot+prof);
            }
            if (next(itr) != maxProfit.end())
                next(itr)->second = max(next(itr)->second, tot);
        }

        return prev(maxProfit.end())->second;
    }
};