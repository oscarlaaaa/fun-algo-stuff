// 2022-10-02
//
// The thought process is that the only time we'd need to remove
// balloons are when we have consecutive balloons with the same colour,
// at which we want to remove all but one. Thus, we isolate the highest
// cost balloon within each consecutive section to keep, and pop the
// rest to make the rope colourful.
//
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int balloon = 0, time = 0;
        while (balloon < n) {
            char curColor = colors[balloon];
            int total = 0, highest = neededTime[balloon];
            while (colors[balloon] == curColor) {
                total += neededTime[balloon];
                highest = max(highest, neededTime[balloon]);
                balloon++;
            }
            time += total - highest;
        }
        return time;
    }
};