// 2022-10-02 (memoized DP)
class Solution {
public:
    unordered_map<string, int> counts;
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
            
        if (s.length() <= 1)
            return 1;

        if (this->counts.count(s))
            return this->counts[s];

        int sum = numDecodings(s.substr(1));
        if (s[0] == '1' || (s[0] == '2' && s[1] - '0' <= 6)) {
            sum += numDecodings(s.substr(2));
        }

        this->counts[s] = sum;
        return sum;
    }
}

// 2022-10-02 (iterative DP)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> memo = vector<int>(n+1, 0);
        memo[0] = 1;

        for (int i=0; i<n; i++) {
            if (memo[i] == 0 || s[i] == '0') 
                continue;

            memo[i+1] += memo[i];

            if (i+2 <= n && (s[i] == '1' || (s[i] == '2' && s[i+1] - '0' <= 6)))
                memo[i+2] += memo[i];
        }

        return memo[n];
    }
};