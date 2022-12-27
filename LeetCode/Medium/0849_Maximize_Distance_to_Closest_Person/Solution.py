## 01-16-2022 (greedy)
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        max_distance = 1
        empty_seats = 0
        first = True
        
        for seat in seats:
            if seat == 0:
                empty_seats += 1
            else:
                max_distance = max(max_distance, (empty_seats if first else ceil(empty_seats/2)))
                empty_seats = 0
                first = False
                
        if empty_seats != 0:
            max_distance = max(max_distance, empty_seats)
        
        return max_distance