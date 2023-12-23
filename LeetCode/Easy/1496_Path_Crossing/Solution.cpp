// 2023-12-22 (memo)
class Solution {
public:
    bool isPathCrossing(string path) {
        /*
        notes:
        - path[i] can be n s e or w
        - return true if path crosses onto itself at any point
        - isn't this just simulating + tracking coordinates you've visited?

        analysis:
        - time = O(n)
        - space = O(n)
        */
        unordered_map<int, unordered_set<int>> visited;
        visited[0].insert(0);

        unordered_map<char, pair<int, int>> directions = {
            {'S', {1, 0}}, 
            {'N', {-1, 0}}, 
            {'W', {0, -1}}, 
            {'E', {0, 1}}
        };

        int x = 0, y = 0;
        for (char c : path) {
            x += directions[c].first;
            y += directions[c].second;

            if (visited[x].count(y)) {
                return true;
            }

            visited[x].insert(y);
        }

        return false;
    }
};