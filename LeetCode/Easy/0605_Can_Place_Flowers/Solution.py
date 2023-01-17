## 2022-01-17
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if n == 0:
            return True
        
        if len(flowerbed) == 1 or len(flowerbed) == 2:
            return flowerbed[0] == 0 and flowerbed[-1] == 0 and n == 1
        
        remaining_flowers = n
        previously_planted = False
        
        for flower in flowerbed:
            if flower == 0:
                if previously_planted:
                    previously_planted = False
                else:
                    previously_planted = True
                    remaining_flowers -= 1
            else:
                if previously_planted:
                    remaining_flowers += 1
                previously_planted = True
        
        return remaining_flowers <= 0