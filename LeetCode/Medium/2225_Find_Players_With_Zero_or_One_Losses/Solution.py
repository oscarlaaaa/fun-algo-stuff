from typing import *

## 2022-04-20
class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        winners = set()
        losers = dict()
        
        for match in matches:
            if match[0] not in losers:
                winners.add(match[0])
            
            if match[1] in winners:
                winners.remove(match[1])
                
            losers[match[1]] = losers[match[1]]+1 if match[1] in losers else 1
        
        return [sorted(list(winners)), sorted([player for player, losses in losers.items() if losses == 1])]