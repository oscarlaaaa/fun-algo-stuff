from typing import *

## 2022-03-16
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        ## records of what we already have for each row/column/box
        rows = [set([val for val in row if val != "."]) for row in board] 
        columns = [set([board[j][i] for j in range(len(board)) if board[j][i] != "."]) for i in range(len(board))]
        boxes = [[set() for i in range(3)] for j in range(3)]
        for i in range(0, 9):
            for j in range(0, 9):
                if board[i][j] != ".":
                    boxes[int(i / 3)][int(j / 3)].add(board[i][j])
        
        self.fillSudoku(board, 0, 0, rows, columns, boxes)
    
    def fillSudoku(self, board, row, column, rows, columns, boxes) -> bool:
        ## if we managed to go beyond row idx 8, it means we are finished
        if row == 9: 
            return True
        
        ## go down one row if we've reached the end of the column
        if column == 9:
            return self.fillSudoku(board, row+1, 0, rows, columns, boxes)
        
        if board[row][column] == ".":
            for i in range(1, 10):
                if str(i) not in rows[row] and \
                    str(i) not in columns[column] and \
                    str(i) not in boxes[int(row/3)][int(column/3)]:
                    
                    ## try a number we haven't tried yet and check if it results in a solve
                    board[row][column] = str(i)
                    rows[row].add(str(i))
                    columns[column].add(str(i))
                    boxes[int(row/3)][int(column/3)].add(str(i))
                    
                    solved = self.fillSudoku(board, row, column+1, rows, columns, boxes)
                    if solved:
                        return True
                    
                    ## undo number if not solved
                    board[row][column] = "."
                    rows[row].remove(str(i))
                    columns[column].remove(str(i))
                    boxes[int(row/3)][int(column/3)].remove(str(i))
        else:
            return self.fillSudoku(board, row, column+1, rows, columns, boxes)
            