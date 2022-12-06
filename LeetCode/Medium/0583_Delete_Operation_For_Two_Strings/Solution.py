## 2022-06-17 (Top-down approach)
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        memo = [[-1 for _ in range(len(word2))] for x in range(len(word1))]
        
        def longestCommonSequence(idx1, idx2):
            if idx1 >= len(word1) or idx2 >= len(word2):
                return 0
            
            if memo[idx1][idx2] != -1:
                return memo[idx1][idx2]
            
            ## skip word1[idx1] char
            longest = longestCommonSequence(idx1+1, idx2)
            
            ## look for word1[idx1] char
            find_cur = word2.find(word1[idx1], idx2, len(word2))
            if find_cur != -1:
                longest = max(longest, 1 + longestCommonSequence(idx1+1, find_cur+1))
                
            memo[idx1][idx2] = longest
            return memo[idx1][idx2]
        
        longest = longestCommonSequence(0, 0)
        
        return len(word1) + len(word2) - 2*longest

## 2022-06-17 (Bottom-up approach)
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        memo = [[0 for _ in range(len(word2)+1)] for x in range(len(word1)+1)]
        
        for i in range(1, len(word1)+1):
            for j in range(1, len(word2)+1):
                ## if we have a match, we want to mark the indices after the match indicies
                ## with an increment from its previous results
                if word1[i-1] == word2[j-1]:
                    memo[i][j] = memo[i-1][j-1]+1
                else:
                    ## if not a match, we want to carry our previous results forward
                    ## so that we can use it later
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1])
        
        return len(word1) + len(word2) - 2*memo[len(word1)][len(word2)]