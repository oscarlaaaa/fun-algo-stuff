## 2023-02-20 (binary search)
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        """
        input: sorted list of ints
        output: the single int that appears only once

        notes:
        - given that it has to be O(logn), it's obviously binary search
        - length of nums will always be an odd number
        - we probably have to find the spot where the pairs of numbers gets
          misaligned
            - numbers of (x, x+1) where x%2==0 will always be pairs UNTIl the
              point where the single element has been inserted
        - binary search to find the spot, then check numbers around the spot?
            - if numbers are misaligned, then move left
            - otherwise, move right
            - after it concludes, check the numbers around it to see which one is
              the single
        
        analysis:
        - time = O(logn) where n=length of nums
        - space = O(1) 
        """
        if len(nums) == 1:
            return nums[0]
            
        l, r = 0, len(nums)-1
        while l < r-2:
            mid = l + (r-l)//2
            if mid&1 == 1:
                mid -= 1
            
            if nums[mid] == nums[mid+1]:
                l = mid+2
            else:
                r = mid

        return nums[l] if l+1 < len(nums) and nums[l] != nums[l+1] else nums[r]
