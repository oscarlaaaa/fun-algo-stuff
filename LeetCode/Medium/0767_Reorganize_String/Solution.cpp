// 2023-08-22
class Solution {
public:
    string reorganizeString(string s) {
        /*
        notes:
        - rearrange the characters so that no two adjacent are the same
        - seems like we can just grab a count of characters, and iterate through them?
            - won't have repeats as long as we start from the top each time
            - actually we want to alternate between most and second most each time it seems?
                - will have to use a heap for this
        
        analysis:
        - time = O(nlogn)
        - space = O(n)
        */
        unordered_map<char, int> counts;
        for (int i=0; i<s.length(); i++) {
            counts[s[i]]++;
        }

        priority_queue<pair<int, char>> queue;
        for (auto itr = counts.begin(); itr != counts.end(); ++itr) {
            queue.push({itr->second, itr->first});
        }

        string output;
        while (!queue.empty()) {
            auto nextChar = queue.top();
            queue.pop();
            
            if (queue.size() == 0) {
                if (nextChar.first > 1) 
                    return "";
                output += nextChar.second;
                return output;
            }

            auto nextNextChar = queue.top();
            queue.pop();

            output += nextChar.second;
            nextChar.first--;

            output += nextNextChar.second;
            nextNextChar.first--;

            if (nextChar.first > 0)
                queue.push(nextChar);
            if (nextNextChar.first > 0)
                queue.push(nextNextChar);
        }
        return output;
    }
};