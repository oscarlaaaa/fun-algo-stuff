from typing import *
from collections import deque

## 2022-10-30 (access to whole matrix)
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i-1][j-1] != matrix[i][j]:
                    return False
        return True

## 2022-10-30 (access to single row)
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        check = None
        for row in matrix:
            if not check:
                check = deque()
                for val in row:
                    check.append(val)
            else:
                check.pop()
                idx = 1
                for val in check:
                    if val != row[idx]:
                        return False
                    idx += 1
                check.appendleft(row[0])
        return True
                