// 2022-12-15
class MyQueue {
public:
/*
    implement a queue using 2 stacks

    notes:
    - amortized O(1) operations
    - using 2 stacks
*/
    deque<int> s1;
    deque<int> s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push_back(x);
    }
    
    int pop() {
        int val = peek();
        s2.pop_back();
        return val;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push_back(s1.back());
                s1.pop_back();
            }
        }
        return s2.back();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */