// 2022-09-13
//
// start from the front-most cars, and go backwards
// record how long it takes the car to reach the target
// 1. if the next car takes shorter to reach the target, then it is grouped with the front car
// 2. otherwise, it is not grouped and it will be in a separate fleet
//
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> pos_speed;
        for (int i=0; i<position.size(); i++) {
            pos_speed[position[i]] = speed[i];
        }
        
        int fleets = 0;
        double prevTime = -1;
        for (auto car = pos_speed.rbegin(); car != pos_speed.rend(); car++) {
            double timeToReach = (double) (target - car->first) / car->second;
            if (timeToReach > prevTime) {
                fleets++;
                prevTime = timeToReach;
            }
        }
        
        return fleets;
    }
};