## 2023-02-12 (meth)
class Solution:
    """
    input: a low and a high int
    output: the number of odd numbers within the interval range

    notes:
    - we can kinda break it down into 4 situations:
        - both low and high are odd
        - both low and high are even
        - low is odd, high is even
        - low is even, high is odd
    - we want to do something with the difference between the two numbers
    - then based on math, we can calculate that (E, O) = low even, high odd
        - (O, O) = (high - low)//2 + 1
        - (E, E) = (high - low)//2
        - (O, E) = (high - low)//2 + 1
        - (E, O) = (high - low)//2 + 1
    - thus, we can return 1 + (high - low)//2 whenever we have an odd within
      low and/or high, or just (high - low)//2 if they're both even
    
    analysis:
    - time = O(1)
    - space = O(1)
    """
    def countOdds(self, low: int, high: int) -> int:
        return 1 + (high-low)//2 if low&1 == 1 or high&1 == 1 else (high-low)//2