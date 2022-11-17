// 2022-11-16
class Solution {
public:
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        size_t h = hash<string>{}(longUrl);
        string tiny = "https://tinyurl.com/" + to_string(h);
        shortToLong[tiny] = longUrl;
        longToShort[longUrl] = tiny;
        return tiny;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));