// 2023-08-27
class MyStack {
    /*
    notes:
    - push -> push = no cycle
    - pop -> pop = cycle
    - pop -> top = cycle
    - top -> pop = no cycle
    - top -> top = no cycle

    analysis:
    - time:
        - push: O(1)
        - top: O(n)
        - pop: O(n)
        - empty: O(1)
    */
public:
    deque<int> queue;
    bool justPopped = true;
    MyStack() {}
    
    void push(int x) {
        queue.push_back(x);
        justPopped = true;
    }
    
    int pop() {
        if (justPopped)
            cycleToFront();
        int val = queue.front();
        queue.pop_front();
        justPopped = true;
        return val;
    }
    
    int top() {
        if (justPopped)
            cycleToFront();
        justPopped = false;
        return queue.front();
    }
    
    bool empty() {
        return queue.empty();
    }
private:
    void cycleToFront() {
        for (int i=0; i<queue.size()-1; i++) {
            queue.push_back(queue.front());
            queue.pop_front();
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */