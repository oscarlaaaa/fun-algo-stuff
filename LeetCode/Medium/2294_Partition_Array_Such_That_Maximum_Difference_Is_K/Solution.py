## 2025-06-18 sorting
class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        """
        notes:
        - want to partition nums into subsequences so that each element in nums appears in only 
          one subsequence
            - have to keep track of num count to know if we need to continue iterating?
        - each subsequence can only have a max difference of k
        - subsequences don't have to be continuous!!!!!
        
        approach:
        - maybe try a greedy approach by iterating forward?
          - iterate and collect all values where the max - min will be <= 0
          - keep a list of max/min starting from the first val?
        - we can also probably sort and solve it that way - wouldn't be very performant though? 
          - since the sequences dont need to be continuous they're essentially just collections
          - how many times each number appears doesn't matter since they'll be in the same group anyways
        """
        sorted_nums = sorted(nums)
        subsequences = 1
        last_min = sorted_nums[0]

        for num in sorted_nums:
            if num - last_min <= k:
                continue
            
            subsequences += 1
            last_min = num
        
        return subsequences

## 2025-06-18 sorting but bucket-sort style
class SolutionTwo:
    def partitionArray(self, nums: List[int], k: int) -> int:
        min_val, max_val = nums[0], nums[0]
        buckets = set()
        for num in nums:
            buckets.add(num)
            min_val = min(min_val, num)
            max_val = max(max_val, num)
        
        subsequences = 1
        last_min = min_val
        for num in range(min_val, max_val+1):
            if num not in buckets:
                continue

            if num - last_min <= k:
                continue
            
            subsequences += 1
            last_min = num
        
        return subsequences
