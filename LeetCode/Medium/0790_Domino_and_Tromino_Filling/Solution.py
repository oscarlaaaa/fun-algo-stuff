## 2021-12-11 (memoization DP)
class Solution:
    def numTilings(self, n: int) -> int:
        if n == 1:
            return 1
        
        normal_memo = [-1] * (n+1)
        uneven_memo = [-1] * (n+1)
        return self.fillDominoes(n, False, normal_memo, uneven_memo) % (1000000007)
    
    def fillDominoes(self, n, uneven, normal_memo, uneven_memo):
        if n < 0:
            return 0
        
        if n == 0:
            if uneven:
                return 0
            else:
                return 1
        
        memo = uneven_memo if uneven else normal_memo
        
        if memo[n] is not -1:
            return memo[n]
        
        oneHorizontal = 0 if not uneven else self.fillDominoes(n-1, uneven, normal_memo, uneven_memo)
        horizontals = 0 if uneven else self.fillDominoes(n - 2, uneven, normal_memo, uneven_memo)
        vertical = 0 if uneven else self.fillDominoes(n - 1, uneven, normal_memo, uneven_memo)
        tromino = (1 if uneven else 2) * self.fillDominoes(n - (1 if uneven else 2), not uneven, normal_memo, uneven_memo)
        
        
        memo[n] = oneHorizontal + horizontals + tromino + vertical
        return memo[n]
        