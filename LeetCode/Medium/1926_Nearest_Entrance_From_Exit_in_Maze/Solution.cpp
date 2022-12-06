// 2022-11-20 (BFS)
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        /*
        input: a maze with walls ('+') and paths ('.'), and the entrance coordinates
        output: number of steps for the shortest path

        notes:
        - goal is to find the nearest path cell at an edge
        - possible to have no exit

        approach:
        - BFS search using a queue that holds <distance from entrance, coordinates>
        - starting from the entranc:
            - check if current path is an edge; if so, then return the distance value
            - else, fill in current path (so we don't backtrack) and add every adjacent
              empty cell with the current distance + 1 to the queue
        - return -1 if we haven't in the loop
        */
        int m = maze.size(), n = maze[0].size();
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        deque<pair<int, vector<int>>> queue = {{0, entrance}};
        maze[entrance[0]][entrance[1]] = '+';
        while (!queue.empty()) {
            int distance = queue.front().first;
            vector<int> position = queue.front().second;
            queue.pop_front();

            if (distance > 0 && 
                (position[0] == 0 || position[0] == m-1 || position[1] == 0 || position[1] == n-1)) {
                return distance;
            }

            for (pair<int, int> direct : directions) {
                int newX = position[0] + direct.first, newY = position[1] + direct.second;
                if (inBounds(newX, newY, m, n) && maze[newX][newY] == '.') {
                    maze[newX][newY] = '+';
                    queue.push_back({distance+1, {newX, newY}});
                }
            }
        }

        return -1;
    }

    bool inBounds(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};