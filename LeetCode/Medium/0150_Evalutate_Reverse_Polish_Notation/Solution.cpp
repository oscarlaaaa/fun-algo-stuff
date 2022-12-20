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

// 2022-12-16 (stack)
class Solution {
#define ll long long
public:
    unordered_map<string, function<ll(ll, ll)>> ops = {
        {"+", [](const ll a, const ll b) { return a + b; }},
        {"-", [](const ll a, const ll b) { return a - b; }},
        {"*", [](const ll a, const ll b) { return a * b; }},
        {"/", [](const ll a, const ll b) { return a / b; }}
    };

    int evalRPN(vector<string>& tokens) {
        /*
            input: list of strings (either a number, or an operation)
            output: the result of the arithmetic expression

            notes:
            - can utilize a map to control what operation is run
            - each operation happens on the last 2 values, so utilize a stack
            - guaranteed the expression is valid, so you wouldn't have an operation without at least
              2 values prior

            approach:
            - utilize a stack to process values in order
            - utilize our map to detect any operations, otherwise we convert it into an int and push
              onto our stack
            - push the result of our operation onto the stack and continue processing
            - return the result of our ops
        */
        deque<ll> stack;
        for (string& token : tokens) {
            if (!ops.count(token)) {
                stack.push_back(stoi(token));
            } else {
                ll y = stack.back();
                stack.pop_back();
                ll x = stack.back();
                stack.pop_back();

                stack.push_back(ops[token](x, y));
            }
        }
        return (int) stack.back();
    }
};