## 2022-08-30
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        
        decimal_string = "" if (numerator < 0 and denominator < 0) or (numerator > 0 and denominator > 0) else "-"

        numerator, denominator = abs(numerator), abs(denominator)
        
        decimal_string += str(numerator//denominator)
        remainder = numerator%denominator

        if remainder > 0:
            decimal_string += "."

        ## record previous remainders to see if we have had a cycle
        prev_seen = dict()
        while remainder > 0:
            ## cycle detected - add brackets
            if remainder in prev_seen:
                decimal_string = f"{decimal_string[:prev_seen[remainder]]}({decimal_string[prev_seen[remainder]:]})"
                break
            prev_seen[remainder] = len(decimal_string)

            ## multiply by 10 is the same as adding a 0 and bringing it down to the remainder in long division
            remainder *= 10
            decimal_string += str(remainder//denominator)
            remainder %= denominator

        return decimal_string
        