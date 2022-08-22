## 2022-08-21 (no loops/recursion)
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        ## check that only the bits for power-of-4 can be filled
        if n == 0 or n & 0x55555555 != n:
            return False
        
        ## check that there is only 1 bit set
        return n&(n-1) == 0
        