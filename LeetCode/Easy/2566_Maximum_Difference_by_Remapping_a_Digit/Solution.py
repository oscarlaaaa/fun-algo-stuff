class Solution:
    def minMaxDifference(self, num: int) -> int:
        """
        - possible to remap one digit to another digit
        - can get 2 results: smallest possible and largest possible
        - can have leading zeroes

        approach:
        - find most significant digit that can be zero'd for smallest, and 9'd for largest
        - swap em all
        - find diff
        """
        num_arr = str(num)
        smallest_val = []
        for num in num_arr:
            if num == num_arr[0]:
                smallest_val.append('0')
            else:
                smallest_val.append(num)
        
        largest_val = []
        digit_to_swap = None
        for num in num_arr:
            if not digit_to_swap and num != '9':
                digit_to_swap = num

            if digit_to_swap and num == digit_to_swap:
                largest_val.append('9')
                continue

            largest_val.append(num)

        return int("".join(largest_val)) - int("".join(smallest_val))