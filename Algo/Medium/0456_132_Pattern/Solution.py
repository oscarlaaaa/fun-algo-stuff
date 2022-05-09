from typing import *

## doesnt work ree
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        
        lowest = nums[0]
        for i in range(len(nums)-2):
            print(i)
            if nums[i] >= lowest:
                continue
            lowest = nums[i]
            highest = nums[i+1]
            
            for j in range(i+1, len(nums)):
                if nums[j] <= lowest:
                    continue
                    
                if nums[j] > highest:
                    highest = nums[j]
                
                print(f"{lowest} {nums[j]} {highest}")
                if lowest < nums[j] < highest:
                    return True
        
        return False

if __name__ == "__main__":
    s = Solution()
    print(s.find132pattern([-1,3,2,0]))