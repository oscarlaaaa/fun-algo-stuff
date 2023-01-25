// 2023-01-24 (min-heaps)
class Solution {
public:
    #define ll long long
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<pair<int, int>> updatedMeetings;
        for (vector<int>& m : meetings) {
            updatedMeetings.push_back({m[0], m[1]-m[0]});
        }
          
        sort(updatedMeetings.begin(), updatedMeetings.end());
    
        // min heaps
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> currentMeetings; // <endtime, index>
    
        // stores our answer!
        vector<int> numTimesBooked(n, 0);
        for (int i=0; i<n; i++) {
            availableRooms.push(i);
        }
      
        ll time = 0;
        for (auto [startTime, duration] : updatedMeetings) {
            time = time > startTime ? time : startTime;
            // pop off current meetings that will end soon if we have no available rooms
            if (availableRooms.empty() || (!currentMeetings.empty() && currentMeetings.top().first <= time)) {
                time = time > currentMeetings.top().first ? time : currentMeetings.top().first;
                while (!currentMeetings.empty() && currentMeetings.top().first <= time) {
                    availableRooms.push(currentMeetings.top().second);
                    currentMeetings.pop();
                }
            }
              
            // available room always
            currentMeetings.push({time+duration, availableRooms.top()});
            numTimesBooked[availableRooms.top()]++;
            availableRooms.pop();
        }
          
        // find smallest index with the most bookings
        int mostBookings = 0;
        for (int i=0; i<n; i++) {
            if (numTimesBooked[i] > numTimesBooked[mostBookings]) 
                mostBookings = i;
        }
        return mostBookings;
    }
};