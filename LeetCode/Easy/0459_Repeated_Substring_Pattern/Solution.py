## 2023-08-20 (brute)
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        """
        notes:
        - check if a string can be constructed by appending a substring of itself together
        - naive way probably to just break the string into factor of n parts and check equality?
            - determine factors by iterating from 2 to n but man this is so brute force but kinda tired
        - only need to do it up to sqrt(n) since the result of 2 parts would be the same as 4/8/16/etc
        - maybe do a sieve or some shit? idk

        analysis:
        - time = O(n^2)
        - space = O(n) bc we list comp baybee
        """
        n = len(s)
        for i in range(n//2, 0, -1):
            if n%i != 0:
                continue
            
            # if all sections match
            if all([s[j-i:j] == s[j:j+i] for j in range(i, n-i+1, i)]):
                return True

        return False