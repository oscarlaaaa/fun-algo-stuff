## 2025-06-17 - sorting solution
class SolutionOne:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        """
        - arr length is a multiple of 3
        - must divide the array into arrays with a max difference of K
        - this can be solved by just sorting the array and then dividing?
          - can determine whether it's impossible if we can't craft a group in order
        """
        sorted_nums = sorted(nums)
        output = []
        for i, num in enumerate(sorted_nums):
            if i % 3 == 0:
                output.append([])
            
            if len(output[-1]) and num - output[-1][0] > k:
                return []

            output[-1].append(num)

        return output 

## 2025-06-17 - bucket-sort-y solution
class SolutionTwo:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        """
        - arr length is a multiple of 3
        - must divide the array into arrays with a max difference of K
        - bound by the max and min values of the array - technically O(nm) where m is the
          range of values
          - as long as m is less than logn it'll be more efficient than sorting
        """
        min_val, max_val = nums[0], nums[0]
        counts = dict()
        for num in nums:
            counts[num] = counts[num]+1 if num in counts else 1
            min_val = min(min_val, num)
            max_val = max(max_val, num)


        output = [[]]
        for i in range(min_val, max_val+1):
            if i not in counts:
                continue
            
            for _ in range(counts[i]):
                if len(output[-1]) == 3:
                    output.append([])

                if len(output[-1]) and i - output[-1][0] > k:
                    return []

                output[-1].append(i)

        return output 
