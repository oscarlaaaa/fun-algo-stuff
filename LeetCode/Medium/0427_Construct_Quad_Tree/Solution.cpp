/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

// 2023-02-27 (recursion + divide and conquer)
class Solution {
public:
    Node* buildQuadTree(vector<vector<int>>& prefixGrid, int row1, int col1, int row2, int col2) {
        int count = prefixGrid[row2][col2] - prefixGrid[row2][col1] - prefixGrid[row1][col2] + prefixGrid[row1][col1];
        int numCells = (row2-row1)*(col2-col1);

        // all cells are 1s
        if (count == numCells)
            return new Node(true, true);

        // all cells are 0s
        if (count == 0)
            return new Node(false, true);
    
        Node* curNode = new Node(true, false);

        int halfRow = row1+(row2-row1)/2, halfCol = col1+(col2-col1)/2;
        curNode->topLeft = buildQuadTree(prefixGrid, row1, col1, halfRow, halfCol);
        curNode->topRight = buildQuadTree(prefixGrid, row1, halfCol, halfRow, col2);
        curNode->bottomLeft = buildQuadTree(prefixGrid, halfRow, col1, row2, halfCol);
        curNode->bottomRight = buildQuadTree(prefixGrid, halfRow, halfCol, row2, col2);
        return curNode;
    }

    Node* construct(vector<vector<int>>& grid) {
        /*
            input: a 2d grid of 1s and 0s
            output: a quad tree based off of the grid

            notes:
            - seems like we can use prefix-sum 2d style to process this stuff
                - iterate thru; pass current value both right and downwards
                - this way we can get the count of 1s by subtracting the top left corner
                  from the bottom right corner of an area
            - then, we can generate it recursively (if current is leaf, we dont need to break it down)

            analysis:
            - time = O(n^2) where n=length of grid
            - space = O(n^2) where n=length of grid
        */
        int n = grid.size();
        vector<vector<int>> prefixGrid(n+1, vector<int>(n+1));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                prefixGrid[i+1][j+1] += grid[i][j];
                if (j+2 < n+1)
                    prefixGrid[i+1][j+2] += prefixGrid[i+1][j+1];
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i+2 < n+1)
                    prefixGrid[i+2][j+1] += prefixGrid[i+1][j+1];
            }
        }

        return buildQuadTree(prefixGrid, 0, 0, n, n);      
    }
};