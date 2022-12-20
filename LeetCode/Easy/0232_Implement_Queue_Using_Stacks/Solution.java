// 2021-11-16
class MyQueue {
    
    Deque<Integer> queue;
    Deque<Integer> stack;
    
    public MyQueue() {
        queue = new ArrayDeque<Integer>();
        stack = new ArrayDeque<Integer>();
    }
    
    public void push(int x) {
        stack.addFirst(x);
    }
    
    public int pop() {
        shiftStacks(stack, queue);
        int output = queue.pop();
        shiftStacks(queue, stack);
        return output;
    }
    
    private void shiftStacks(Deque<Integer> stack1, Deque<Integer> stack2) {
        while (!stack1.isEmpty()) {
            stack2.addFirst(stack1.pop());
        }
    }
    
    public int peek() {
        shiftStacks(stack, queue);
        int output = queue.getFirst();
        shiftStacks(queue, stack);
        return output;
    }
    
    public boolean empty() {
        return stack.size() == 0;
    }
    
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */