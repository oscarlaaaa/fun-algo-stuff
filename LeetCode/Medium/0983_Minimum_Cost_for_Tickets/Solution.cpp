// 2023-03-28 (tabulation)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        /*
        notes:
        - days is a list of values from 1 to 365
        - tickets can either be bought for 1, 7, or 30 days
        - want to minimize the total $$ spent to reach the last day
        - don't we just iterate until we reach the thresholds?
        - this is definitely DP so we need to have n slots for our tabulation
        - just iterate until we hit thresholds for 1/7/30 for each day slot?

        analysis:
        - time = O(n) where n=length of days (though technically max is 365*30 so we can say O(1))
        - space = O(n) where n=length of days (though technically max is 365*30 so we can say O(1))
        */
        int n = days.size();
        // represents smallest cost to reach day i where day[i] = tab[i+1];
        vector<int> tab(n+1, INT_MAX); 
        tab[0] = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n+1 && days[j-1]-days[i] < 30; j++) {
                int dayDiff = days[j-1]-days[i];
                if (dayDiff < 1) // 1 day ticket
                    tab[j] = min(tab[j], tab[i]+costs[0]);
                if (dayDiff < 7) // 7 day ticket
                    tab[j] = min(tab[j], tab[i]+costs[1]);
                if (dayDiff < 30) // 30 day ticket
                    tab[j] = min(tab[j], tab[i]+costs[2]);
            }
        }

        return tab.back();
    }
};