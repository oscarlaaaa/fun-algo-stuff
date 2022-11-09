class StockSpanner:
    """
    span = max number of prior consecutive days where price was <= today's price (including self)

    monotonic stack of tuples (val, num of consec. values smaller than it)
    - if price is >= top of stack, pop off and add the num values smaller than it to your ototal
        - once price is empty or you reach a val > price, then add 1, put onto stack (index, total)
          and output
    """

    def __init__(self):
        self.greater_than = []
        
    def next(self, price: int) -> int:
        total = 1
        while self.greater_than and price >= self.greater_than[-1][0]:
            total += self.greater_than[-1][1]
            self.greater_than.pop()
        self.greater_than.append((price, total))
        return total


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)