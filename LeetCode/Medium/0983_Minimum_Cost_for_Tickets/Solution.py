## 2021-11-25 (memoization)
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        cheapest = [-1] * len(days)
        return self.findCheapestPlan(days, costs, cheapest)
    
    def findCheapestPlan(self, days: List[int], costs: List[int], cheapest: List[int]) -> int:
        if len(days) == 0:
                return 0
        
        position = len(cheapest) - len(days)
        
        if cheapest[position] != -1:
            return cheapest[position]
        
        one_day_price = costs[0] + self.findCheapestPlan(days[1:], costs, cheapest)
        
        current_day = days[0]-1
        future_day = 0
        
        while future_day < len(days) and days[future_day] - current_day <= 7:
            future_day = future_day + 1
        seven_day_price = costs[1] + self.findCheapestPlan(days[future_day:], costs, cheapest)
        
        while future_day < len(days) and days[future_day] - current_day <= 30:
            future_day = future_day + 1
        thirty_day_price = costs[2] + self.findCheapestPlan(days[future_day:], costs, cheapest)
        
        cheapest[position] = min(one_day_price, seven_day_price, thirty_day_price)
        return cheapest[position]