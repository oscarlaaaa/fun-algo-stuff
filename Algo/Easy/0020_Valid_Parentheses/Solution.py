from typing import *

# 2022-03-12
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 1:
            return False
        
        stack = []
        leftBrackets = {'{': '}', '[': ']', '(': ')'}
        
        for bracket in s:
            if bracket in leftBrackets:
                stack.append(bracket)
            else:
                if len(stack) == 0:
                    return False
                
                previous = stack.pop()
                if bracket != leftBrackets[previous]:
                    return False
        
        return len(stack) == 0