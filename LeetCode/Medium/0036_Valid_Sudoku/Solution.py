from typing import *

## 2022-08-18
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        ## validate horizontals
        vertical, horizontal = set(), set()
        for i in range(9):
            for j in range(9):
                if board[i][j] in horizontal or board[j][i] in vertical:
                    return False
                if board[i][j] != ".":
                    horizontal.add(board[i][j])
                if board[j][i] != ".":
                    vertical.add(board[j][i])
            horizontal.clear()
            vertical.clear()
        
        ## validate 3x3 blocks
        block = set()
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                for x in range(i, i+3):
                    for y in range(j, j+3):
                        if board[x][y] in block:
                            return False
                        if board[x][y] != ".":
                            block.add(board[x][y])
                block.clear()
        
        return True
        