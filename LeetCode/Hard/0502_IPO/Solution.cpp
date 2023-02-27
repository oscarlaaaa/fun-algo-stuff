// 2023-02-27 (priority queue + muiltiset)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        /*
            input: k projects, w starting capital, a list of profits, and a list of capital needed to start
            output: final maximized kapital after investing in at most k distinct projects

            notes:
            - seems like our options are limited by our available capital, and we just have to
              pick the best option 
                - couldn't we handle this with a priority queue?
            - what situation would you not want to take K projects?
                - only if you can't afford to start any? that seems to be the only one
            - wouldn't it just be greedy choice of choosing the option that gives you the most
              profit at each point?
                - resultant time is O(nlogn), but that doesn't seem too bad? might TLE though
                - kind of hard as if we want to optimize by limiting heap to size k, then we need to be able to
                  pop off the smallest value to shrink it while also being able to grab the
                  largest value to invest in
            - we probably need to establish:
                - how to grab most profitable project possible (map)
                - how to limit our map to size K
            
            analysis:
            - time = O(nlogn + nlogk) where n=length of profits/capital
            - space = O(n) where n=length of profits/capital
        */
        int n = profits.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> projectQueue;
        for (int i=0; i<n; i++) {
            projectQueue.push({capital[i], profits[i]});
        }

        int money = w;
        multiset<int> bestProjects;
        for (int i=0; i<k; i++) {
            while (!projectQueue.empty() && projectQueue.top().first <= money) {
                bestProjects.insert(projectQueue.top().second);
                projectQueue.pop();
                if (bestProjects.size() > k-i) {
                    bestProjects.erase(bestProjects.find(*(bestProjects.begin())));
                }
            }

            if (bestProjects.empty())
                break;

            int bestOption = *(bestProjects.rbegin());
            money += bestOption;
            bestProjects.erase(bestProjects.find(bestOption));
        }
        return money;
    }
};