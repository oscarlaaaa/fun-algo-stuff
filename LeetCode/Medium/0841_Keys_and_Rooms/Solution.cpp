// 2022-12-19 (BFS)
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        /*
            input: list of rooms with a list of keys present within
            output: bool whether you can visit all rooms

            notes:
            - there can be duplicate keys within rooms
            
            approach:
            - rooms essentially represents a graph, with keys being
              the currently accessible rooms
            - keep track of what rooms we've visited, and what keys we have
            - BFS starting from room 0
              - each key within the room will represent what rooms we can visit after
                so queue it up in our queue (if we haven't visited/added it already)
              - mark down current room as visited
            - return whether every room has been visited
        */
        int n = rooms.size();
        deque<int> queue = {0};
        vector<bool> grabbedKey(n);
        grabbedKey[0] = true;
        while (!queue.empty()) {
            int currentRoom = queue.front();
            queue.pop_front();

            for (int& key : rooms[currentRoom]) {
                if (grabbedKey[key]) 
                    continue;
                
                grabbedKey[key] = true;
                queue.push_back(key);                
            }
        }

        return all_of(grabbedKey.begin(), grabbedKey.end(), [](bool b) {return b;});
    }
};