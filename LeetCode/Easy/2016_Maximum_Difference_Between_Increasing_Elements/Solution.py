class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        """
        - find the maximum difference between nums[i] and nums[j] where i < j and nums[i] < nums[j]

        approach:
        - traverse forwards, keeping record of lowest value
        - if you encounter lower value, mark it as your lowest
            - we can do this because we want to track the lowest to the left of any other values we encounter
        - if you encounter higher value, get difference and see if it's greater than the max diff
        """
        greatest_diff = 0
        lowest_val = nums[0]
        for num in nums:
            if num < lowest_val:
                lowest_val = num
            
            greatest_diff = max(greatest_diff, num - lowest_val)
        
        return -1 if greatest_diff == 0 else greatest_diff 

