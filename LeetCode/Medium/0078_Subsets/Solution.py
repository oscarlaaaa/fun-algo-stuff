from typing import *

## 2021-12-14 (backtracking)
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subset_list = []
        self.find_all_subsets(nums, 0, [], subset_list)
        return subset_list
    
    def find_all_subsets(self, nums, position, current_subset, subset_list):
        if position >= len(nums):
            subset_list.append(current_subset.copy())
            return
        
        self.find_all_subsets(nums, position + 1, current_subset, subset_list)
        
        current_subset.append(nums[position])
        self.find_all_subsets(nums, position + 1, current_subset, subset_list)
        current_subset.pop()
        
## 2022-11-03 (backtracking)
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def find_subsets(nums, idx, cur_set, sets):          
            sets.append(cur_set[:])
            for i in range(idx, len(nums)):
                cur_set.append(nums[i])
                find_subsets(nums, i+1, cur_set, sets)
                cur_set.pop()

        sets = []
        find_subsets(nums, 0, [], sets)
        return sets
