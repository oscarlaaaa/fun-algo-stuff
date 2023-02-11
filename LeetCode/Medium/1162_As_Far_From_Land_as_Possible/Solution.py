## 2023-02-11 (BFS)
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        """
        input: an nxn grid where 0 = water and 1 = land
        output: the shortest distance from a water cell with the maximum distance from land

        notes:
        - distance between a and b would be |ax-bx| + |ay-by|
        - we could probably pre-process this? basically iterate from every single direction and
          keep track of the nearest land from that direction
            - would turn into an O(8n^2) solution? that's probably okay tho right
            - actually! it's not just 8 directions as we need distance from everything
        - BFS out from every land piece?
            - every iteration of BFS would be 1 distance from land
            - as long as we don't re-queue the same values it might be pretty good (O(n^2))
            - last remaining non-affected water will have the greatest distance
            - we can actually just go vertical/horizontal as hitting a diagonal piece with a vert+hori
              will give us the correct manhattan distance anyways
        
        analysis:
        - time = O(n^2) where n=length of grid
        - space = O(n^2) where n=length of grid
        """
        n = len(grid)
        seen = set()
        queue = []

        directions = [(0,1), (1,0), (-1,0), (0,-1)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    queue.append((i, j))

        ## if all waters or all lands, return -1
        if len(queue) == 0 or len(queue) == n*n:
            return -1
            
        maximum_dist = -1
        while queue:
            maximum_dist += 1
            next_queue = []
            for x, y in queue:
                for x_inc, y_inc in directions:
                    ## if next cell is in bounds, is water, and hasn't been added
                    if 0 <= x+x_inc < n and 0 <= y+y_inc < n \
                            and grid[x+x_inc][y+y_inc] == 0 \
                            and (x+x_inc, y+y_inc) not in seen:
                        next_queue.append((x+x_inc, y+y_inc))
                        seen.add((x+x_inc, y+y_inc))
            queue = next_queue

        return maximum_dist
