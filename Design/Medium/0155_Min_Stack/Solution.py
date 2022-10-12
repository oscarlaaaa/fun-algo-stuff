## 2022-10-11 (double stack)
class MinStack:
    def __init__(self):
        self.stack = []
        self.minimums = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if not self.minimums or val < self.stack[self.minimums[-1]]:
            self.minimums.append(len(self.stack)-1)

    def pop(self) -> None:
        if len(self.stack)-1 == self.minimums[-1]:
            self.minimums.pop()
        self.stack.pop()
        
    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.stack[self.minimums[-1]]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()