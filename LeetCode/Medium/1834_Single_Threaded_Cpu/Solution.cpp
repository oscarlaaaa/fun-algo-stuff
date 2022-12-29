// 2022-12-28 (sorting + priority queue)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        /*
            input: list of tasks where a task is [enqueue time, process time]
            output: the order that the cpu will process the tasks

            notes:
            - 2 cases
              - CPU is idle, and no available tasks -> remain idle
              - CPU is idle and available tasks -> choose shortest processing time (or smallest idx)
            - CPU processes entire task without stopping
            - CPU finishes the task and starts a new one instantly
            - have to sort the tasks somehow?
            - sorted list of enqueue times; maybe a sorted map?
              - map is <enqueue time, <processing time, index>>?
              - can maybe use a pq to organize times that we've queued up

            approach:
            - for each task, push into a map as a pair like <processing time, index> with the enqueue time as a key
            - get a pointer to the start of our map (sorted), and start our time at the key
              value of our first enqueue time
            - keep track of our current time
            - check whether we can add our next sequence of tasks if we either run out of tasks, or if our time is past the enqueue time
              - if we can, then add our tasks into our PQ from our pointer, then increment pointer
              - if we add tasks that are further ahead than our current time, then reassign time
            - pop off times from our PQ in order of shortest processing, then push indices onto our output list
            - return the ordering
        */
        int n = tasks.size();

        // organize tasks according to their enqueue time
        map<int, vector<pair<int, int>>> taskGroups;
        for (int i=0; i<n; i++) {
            taskGroups[tasks[i][0]].push_back({tasks[i][1], i});
        }

        // the pq should short as a min heap according to the processing time, then the index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> taskQueue;

        // sorted map, so pointer will go from lowest to highest enqueue time
        auto groupPointer = taskGroups.begin();

        vector<int> output;
        long long currentTime = groupPointer->first;
        while (groupPointer != taskGroups.end() || !taskQueue.empty()) {
            // queue tasks if we either have none left or if we've passed enqueue times of some tasks
            while (groupPointer != taskGroups.end() && (groupPointer->first <= currentTime || taskQueue.empty())) {
                for (auto task : groupPointer->second) {
                    taskQueue.push(task);
                }
                currentTime = max(currentTime, 1LL*groupPointer->first);
                groupPointer++;
            }
            auto [processing, index] = taskQueue.top();
            currentTime += processing;
            output.push_back(index);
            taskQueue.pop();
        }
        
        return output;
    }
};