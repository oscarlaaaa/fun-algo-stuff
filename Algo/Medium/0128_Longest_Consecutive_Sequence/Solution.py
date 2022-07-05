from typing import *

## 2022-03-16 (Union-find approach)
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        distinct_nums = set(nums)
        groups = dict()  ## holds the various groups (sets of numbers)
        groupings = dict()  ## keeps track of what group index a number is in
        cur_group_num = 0
        
        for num in distinct_nums:
            groupings[num] = -1  ## -1 grouping value means it doesn't currently have a group
        
        for num in distinct_nums:
            current_group = groupings[num]
            
            if current_group == -1: ## if current num doesn't have a group yet, create a new group
                groups[cur_group_num] = set([num])
                current_group = cur_group_num
                cur_group_num += 1
            
            if num-1 in distinct_nums:
                if groupings[num-1] == -1:
                    groups[current_group].add(num-1)
                    groupings[num-1] = current_group
                elif groupings[num-1] != current_group:
                    groups[current_group] = groups[current_group] | groups[groupings[num-1]]
                
            if num+1 in distinct_nums:
                if groupings[num+1] == -1:
                    groups[current_group].add(num+1)
                    groupings[num+1] = current_group
                elif groupings[num+1] != current_group:
                    groups[current_group] = groups[current_group] | groups[groupings[num+1]]
        
        return max(len(group) for group in groups.values())
                

## 2022-07-04 (Pseudo-'Linked List' approach)
class Solution:   
    def longestConsecutive(self, nums: List[int]) -> int:
        nodes = dict()
        seen = set()
        longest = 0
        
        for num in nums:
            if num in nodes:
                continue
                
            ## create a 'linked-list' node, and connect it to neighbours if present
            nodes[num] = [False, False]
            if num-1 in nodes:
                nodes[num-1][1] = nodes[num][0] = True
            if num+1 in nodes:
                nodes[num+1][0] = nodes[num][1] = True
        
        ## find longest continuous 'linked-list' string
        for num in nums:
            if num in seen:
                continue
            seen.add(num)
            
            left = right = num
            while nodes[left][0]:
                left -= 1
                seen.add(left)
            while nodes[right][1]:
                right += 1
                seen.add(right)
            
            longest = max(longest, right - left + 1)
            
        return longest
                