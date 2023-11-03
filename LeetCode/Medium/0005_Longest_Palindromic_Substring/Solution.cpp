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

// 2023-10-27 (optimized brute force)
class Solution {
public:
    string longestPalindrome(string s) {
        /*
        notes:
        - queue up single chars + pairs of matching chars
        - iterate outwards, recording longest substring spotted so far
            - queue up new pairs of chars if they match
        - kinda hard to prac this since i've done it so many times

        analysis:
        - time = O(n^2)
        - space = O(n)
        */
        int n = s.length();
        pair<int, int> longest = {0,0};
        deque<pair<int, int>> queue;
        for (int i=0; i<n; i++) {
            queue.push_back({i, i});
            if (i < n-1 && s[i] == s[i+1]) {
                queue.push_back({i, i+1});
                longest = {i, i+1};
            }
        }

        while (!queue.empty()) {
            auto [l, r] = queue.front();
            queue.pop_front();
            int newL = l-1, newR = r+1;

            if (newL >= 0 && newR < n && s[newL] == s[newR]) {
                queue.push_back({newL, newR});
                if (newR-newL+1 > longest.second - longest.first + 1) {
                    longest = {newL, newR};
                }
            }
        }
        auto [start, end] = longest;
        return s.substr(start, end-start+1);
    }
};