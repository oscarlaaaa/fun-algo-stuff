class Solution:
    def maxDiff(self, num: int) -> int:
        """
        - apply the following steps to num 2 separate times:
            1. pick a digit X and a digit Y
            2. replace all occurrences of X in num with Y
        - return the max difference between A and B results

        constraints:
        - No leading zeroes
        - number cannot turn into a zero

        approach:
        1. replace first digit with a 1 or 9 if possible
        2. if not, then replace next digit with 0 or 9 if possible
        """
        return self.get_highest_number(num) - self.get_lowest_number(num)
    
    def get_lowest_number(self, num: int) -> int:
        stringified_digits = list(str(num))
        digit_to_swap = None
        swap_to_zeroes = True

        if stringified_digits[0] != '1':
            digit_to_swap = stringified_digits[0]
            swap_to_zeroes = False
        else:    
            for i, digit in enumerate(stringified_digits):
                if i == 0:
                    continue
                
                ## skip 1 as well because if we hit this loop, our first number is a 1
                ## and so we cannot change it to a zero
                if digit != '0' and digit != '1':
                    digit_to_swap = digit
                    break

        if digit_to_swap is None:
            return num
        
        for i, digit in enumerate(stringified_digits):
            if digit != digit_to_swap:
                continue

            stringified_digits[i] = '0' if swap_to_zeroes else '1'

        return int("".join(stringified_digits))

    def get_highest_number(self, num: int) -> int:
        stringified_digits = list(str(num))
        digit_to_swap = None
        for i, digit in enumerate(stringified_digits):
            if digit_to_swap:
                if digit == digit_to_swap:
                    stringified_digits[i] = '9'
                    continue
            elif digit != '9':
                digit_to_swap = digit
                stringified_digits[i] = '9'

        return int("".join(stringified_digits))