// 2022-12-05
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        /*
            input: grid of different types of streets
            output: whether there's a valid path

            notes:
            - 1 = left->right
            - 2 = top->bottom
            - 3 = left->bottom
            - 4 = right->bottom
            - 5 = top->left
            - 6 = top->right

            - Just need to follow a path and see if we can run through everything
              to end up at (m-1, n-1)
            
            approach:
            - map of the entrance for each street
            - map of what each street direction can connect to
            - start at 0,0
            - check that both ends are valid
            - mark current street as -1 and move forward
        */
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        // what road each movement direction can move into
        vector<vector<bool>> validStreets = {
            {0,1,0,1,0,1,0},
            {0,0,1,0,0,1,1},
            {0,0,1,1,1,0,0},
            {0,1,0,0,1,0,1},
        };

        // the openings of each path type
        vector<vector<int>> canTravel = {{},
            {0, 3}, {1, 2}, {1, 3},
            {0, 1}, {2, 3}, {0, 2}
        };
        
        deque<pair<int, int>> queue = {{0,0}};
        while (!queue.empty()) {
            auto [x,y] = queue.front();
            queue.pop_front();

            if (x == m-1 && y == n-1) 
                return true;

            int curStreet = grid[x][y];
            grid[x][y] = 0;
            for (int move : canTravel[curStreet]) {
                auto& [i,j] = directions[move];
                if (inBounds(x+i, y+j, m, n) && validStreets[move][grid[x+i][y+j]]) {
                    queue.push_back({x+i, y+j});
                }
            }
        }

        return false;
    }

    bool inBounds(int x, int y, int m, int n) {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
};