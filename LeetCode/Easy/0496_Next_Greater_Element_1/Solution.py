## 2022-01-04 (stack)
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        """
            Using a stack, iterate through nums2 to determine the next
            greatest element. We only store values in the stack from greatest (bottom)
            to lowest (top). 
            
            If we encounter a number that is greater than the top of
            our stack, we assign the top number's next greatest as the number we've 
            encountered in a dictionary, and pop it off our stack. 
            
            We continue until the top of the stack is greater than our current number, or 
            if our stack runs out. We then push the current number onto our stack and continue
            until we finish iterating through nums2.
            
            We can then generate the output list using our dictionary.

            This works since there's a guarantee that all numbers in nums1 and nums2 will
            be unique, so our greater assignments won't overwrite each other.
        """
        greater = dict()
        stack = []
        for num in nums2:
            while stack and num > stack[-1]:
                greater[stack[-1]] = num
                stack.pop()
            stack.append(num)
        return [greater[num] if num in greater else -1 for num in nums1]