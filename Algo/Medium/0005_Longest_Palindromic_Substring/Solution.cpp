// 2022-06-18 (optimized brute force approach)
class Solution {
public:
    string longestPalindrome(string s) {
        deque<pair<int, int>> queue;
        for (int i=1; i<s.length(); i++) {
            queue.push_back({i-1, i});
            if (i < s.length()-1)
                queue.push_back({i-1, i+1});
        }

        pair<int, int> longest = {0, 0};
        while (!queue.empty()) {
            pair<int, int> cur = queue.front();
            queue.pop_front();
            if (cur.first >= 0 && cur.second < s.length() && s[cur.first] == s[cur.second]) {
                queue.push_back({cur.first-1, cur.second+1});
                if (longest.second - longest.first < cur.second - cur.first)
                    longest = cur;
            }
        }
        
        return s.substr(longest.first, longest.second - longest.first + 1);
    }
};