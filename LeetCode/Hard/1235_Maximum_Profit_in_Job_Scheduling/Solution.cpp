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

// 2024-01-05 (heap)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        /*
        notes:
        - n jobs with start/end times, and want to maximize profit
        - we probably need to sort by start-time so that we have some order in our iteration
        - we also need to keep a sorted list of end-times so that we can add onto the profit
          from previous times
        - while iterating, track current largest profit from the encounters we process?
          - we can track profit by using a minheap that stores {endtime, curmaxprofit + jobprofit} and
            popping off the top until the next endtime is > our current start time

        analysis:
        - time = O(nlogn)
        - space = O(n)
        */
        int n = startTime.size();

        // sort jobs together according to start-time
        std::vector<pair<int, pair<int, int>>> jobs;
        for (int i=0; i<n; i++) {
            jobs.push_back({profit[i], {startTime[i], endTime[i]}});
        }    
        std::sort(jobs.begin(), jobs.end(), [](pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
            return a.second.first < b.second.first;
        });

        std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int maxProfit = 0;
        for (auto [profit, time] : jobs) {
            auto [startTime, endTime] = time;

            // grab profits from previous start times and use the largest one so far
            while (!minHeap.empty() && startTime >= minHeap.top().first) {
                maxProfit = std::max(maxProfit, minHeap.top().second);
                minHeap.pop();
            }

            // push our resultant profit for use at/after our end-time
            minHeap.push({endTime, maxProfit + profit});
        }

        // for the last ones we haven't processed yet
        while (!minHeap.empty()) {
            maxProfit = std::max(maxProfit, minHeap.top().second);
            minHeap.pop();
        }

        return maxProfit;
    }
};