## 2023-02-14
class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        """
        input: array of nums, and an int k
        output: the array form added with the integer

        notes:
        - if we have to append a 1 to the end that'd b a pain kinda
            - although it'd probably be the same time compelx anyways
        - use / and % to get the digit + shift values downwards
        - we can do add -> process to find remainder/carry afterwards

        analysis
        - time = O(n) where n=length of num
        - space = O(n) where n=length of num
        """
        arr = list(reversed(num))
        digit, remain = 0, k
        while remain > 0:
            if digit >= len(arr):
                arr.append(0)
            arr[digit] += remain % 10
            remain = remain // 10
            digit += 1

        for i in range(len(arr)):
            carry = arr[i] // 10
            arr[i] %= 10

            if carry and i >= len(arr)-1:
                arr.append(1)
            elif carry:  
                arr[i+1] += carry

        return reversed(arr)