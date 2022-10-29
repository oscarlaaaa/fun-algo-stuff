from typing import *

## 2022-10-29 (sorted + greedy)
class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        """
        plantTime = days to plant
        growTime = days to grow

        - cannot be planting multiple plants at the same time (active task)
        - plants can be growing at the same time (passive task)
        
        - plant time order doesn't seem to matter much? need to spend sum(plantTime) days to plan on minimum
        - grow tiem order matters - want longest-growing plants first
        
        """        
        order_to_plant = sorted(zip(growTime, plantTime), key=lambda x: -x[0])
        cur_day, latest_bloom = 0, 0
        for grow, plant in order_to_plant:
            cur_day += plant
            latest_bloom = max(latest_bloom, cur_day+grow)
        return latest_bloom
