## 2022-04-18
class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        counts = dict()
        for diff in tasks:
            counts[diff] = counts[diff]+1 if diff in counts else 1
        
        total_rounds = 0
        for value in counts.values():
            if value < 2:
                return -1
            total_rounds += ceil(value / 3)
        
        return total_rounds