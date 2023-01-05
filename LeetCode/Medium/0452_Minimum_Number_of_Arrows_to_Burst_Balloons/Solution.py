## 2022-01-13 (sort and greedy)
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        sorted_balloons = sorted(points, key=lambda x: x[1])
        arrows = 1
        popped = 0
        height = sorted_balloons[0][1]
        
        while popped < len(sorted_balloons):
            if height < sorted_balloons[popped][0]:
                height = sorted_balloons[popped][1]
                arrows += 1
            popped += 1
        
        return arrows