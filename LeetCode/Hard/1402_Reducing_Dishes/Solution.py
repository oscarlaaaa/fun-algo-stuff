from typing import *

# 2022-04-21
class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        if max(satisfaction) <= 0:
            return 0
        
        # reverse list so we can add most valuable dishes 'first'
        satisfaction.sort(reverse=True)
            
        current_dishes = 0
        total = 0
        
        # adding dishes in reverse chronological order (first add = greatest time bonus)
        for val in satisfaction:
            # dishes added first will be added to total
            # every subsequent iteration (summation)
            current_dishes += val

            # terminate once negative satisfaction from dishes
            # outweighs the time benefit
            if current_dishes < 0:
                break

            total += current_dishes
        
        return total
    