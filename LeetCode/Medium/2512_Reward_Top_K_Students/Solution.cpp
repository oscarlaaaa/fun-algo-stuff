// 2023-04-19 (priority queue)
class Solution {
private:
    vector<string> tokenize(string s) {
        vector<string> tokens = {""};
        for (char c : s) {
            if (c == ' ')
                tokens.push_back("");
            else
                tokens.back() += c;
        }
        return tokens;
    }
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        /*
        notes:
        - 2 string arrays with positive and negative words, a string array of student reports, and k students to select
        - positive words +3, negative words -1
        - ?? isn't this just counting up points for each student and sorting them out basically
        - we can just process and insert each one in to a max PQ as a pair of <score, id>
            - i fucking hate dealing with pqs so lets do ez sorting 8)
            - actually i did pq anyways to optimize runtime
        
        complexity:
        - time = O(nlogk) where n=num of students
        - space = O(n+k) where n=num of students
        */
        int n = student_id.size();
        unordered_map<string, int> values;
        for (string& w : positive_feedback)
            values[w] = 3;
        for (string& w : negative_feedback)
            values[w] = -1;

        auto comp = [](pair<int, int>& s1, pair<int, int>& s2) {
            if (s1.first != s2.first)
                return s1.first > s2.first; // larger score first
            return s1.second < s2.second;   // smaller ID first
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> topK(comp); 
        for (int i=0; i<n; i++) {
            int score = 0;
            vector<string> tokens = tokenize(report[i]);
            for (string& word : tokens) 
                score += values[word];
                
            topK.push({score, student_id[i]});
            if (topK.size() > k)
                topK.pop();
        }

        vector<int> output;
        while (!topK.empty()) {
            output.push_back(topK.top().second);
            topK.pop();
        }
        reverse(output.begin(), output.end()); // flip since our list will be lowest -> highest after popping

        return output;
    }
};