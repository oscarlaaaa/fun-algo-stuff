from typing import *

## 2022-05-04
class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        cells = []
        bounds = s.split(":")
        upper_col = ord(bounds[1][0]) - ord(bounds[0][0]) + 1
        upper_row = int(bounds[1][1]) - int(bounds[0][1]) + 1
        for i in range(upper_col):
            for j in range(upper_row):
                cells.append(f"{chr(ord(bounds[0][0]) + i)}{int(bounds[0][1]) + j}")
                
        return cells

## 2022-05-04 (more clear)
class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        cells = []
        bounds = s.split(":")
        lower_col, upper_col = ord(bounds[0][0]), ord(bounds[1][0])
        lower_row, upper_row = int(bounds[0][1]), int(bounds[1][1])
        for i in range(lower_col, upper_col+1):
            for j in range(lower_row, upper_row+1):
                cells.append(f"{chr(i)}{int(j)}")
                
        return cells