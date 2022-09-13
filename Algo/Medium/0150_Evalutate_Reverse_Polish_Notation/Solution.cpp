// 2022-09-13 (stack)
class Solution {
public:
    #define ll long long
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> operations = {"+", "-", "/", "*"};
        deque<ll> values;
        
        for (string token : tokens) {
            if (operations.count(token)) {
                ll value2 = values.back();
                values.pop_back();
                ll value1 = values.back();
                values.pop_back();
                
                ll result = 0;
                if (token == "+") {
                    result = value1 + value2;
                } else if (token == "-") {
                    result = value1 - value2;
                } else if (token == "/") {
                    result = value1 / value2;
                } else {
                    result = value1 * value2;
                }
                values.push_back(result);
                
            } else {
                values.push_back(stoi(token));
            }
        }
        
        return values.back();
    }
};