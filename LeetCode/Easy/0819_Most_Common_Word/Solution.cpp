// 2023-04-07
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        /*
        notes:
        - probably tokenize the paragraph, remove any unnecessary chars, and convert
          into lowercase before counting occurrences?
        - add to counts if not in our banned list
        - use maps/sets to organize everything easily

        analysis:
        - time: O(n) where n=length of paragraph
        - space = O(n) where n=legnth of paragraph
        */
        int n = paragraph.length();
        unordered_map<string, int> counts;
        unordered_set<string> noBueno(banned.begin(), banned.end());
        noBueno.insert("");
        
        string token = "", mostCommon = "";
        for (int i=0; i<=n; i++) {
            if (i == n || !isalpha(paragraph[i])) {
                if (!noBueno.count(token)) {
                    counts[token]++;
                    if (counts[token] > counts[mostCommon])
                        mostCommon = token;
                }
                token = "";
            } else {
                token += tolower(paragraph[i]);
            }
        }

        return mostCommon;
    }
};