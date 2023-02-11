## 2023-02-11 (DFS)
class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        """
        input: int n number of nodes, red edges, and blue edges
        output: the shortest path from 0 to x such that edges alternate

        notes:
        - i feel like the best way would be just to BFS to find shortest route?
        - maybe record red edges and blue edges separately as well
            - this way, we can alternate which edges we search from
            - although we might run into issues with loops and whatnot
        - self loops are probably never useful as to reach it, we would need to have taken the
          other colour and after taking it, we'd can only take the other colour anyways
        - looping onto itself is ok as long as it's from a different colour
            - probably BFS
            - one for coming from red, one for coming from blue
        """
        shortest = {
            "red": [0] + [-1 for _ in range(n-1)],
            "blue": [0] + [-1 for _ in range(n-1)]
        }
        reds, blues = [[] for _ in range(n)], [[] for _ in range(n)]
        for edge in redEdges:
            reds[edge[0]].append(edge[1])
        for edge in blueEdges:
            blues[edge[0]].append(edge[1])
        
        def alternatingDfs(node, red_edges, blue_edges, last_colour, memo):
            edges = blue_edges if last_colour == "red" else red_edges
            cur_colour = "blue" if last_colour == "red" else "red"

            dist = memo[cur_colour][node]
            for edge in edges[node]:
                if memo[last_colour][edge] == -1 or memo[last_colour][edge] >= dist+1:
                    memo[last_colour][edge] = dist+1
                    alternatingDfs(edge, red_edges, blue_edges, cur_colour, memo)
        
        alternatingDfs(0, reds, blues, "red", shortest)
        alternatingDfs(0, reds, blues, "blue", shortest)
        output = []
        for i in range(n):
            if shortest['red'][i] == -1 or shortest['blue'][i] == -1:
                output.append(max(shortest['red'][i], shortest['blue'][i]))
            else:
                output.append(min(shortest['red'][i], shortest['blue'][i]))
        return output

## 2023-02-11 (BFS)
class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        """
        input: int n number of nodes, red edges, and blue edges
        output: the shortest path from 0 to x such that edges alternate

        notes:
        - i feel like the best way would be just to BFS to find shortest route?
        - maybe record red edges and blue edges separately as well
            - this way, we can alternate which edges we search from
            - although we might run into issues with loops and whatnot
        - self loops are probably never useful as to reach it, we would need to have taken the
          other colour and after taking it, we'd can only take the other colour anyways
        - looping onto itself is ok as long as it's from a different colour
            - probably BFS
            - one for coming from red, one for coming from blue
        - we only queue up elements if we've reached them for the first time for that colour as BFS
          guarantees that the first time we see it will be the shortest path
        - create output by assigning output[i] as -1 if never reached by both colours, or the lesser of
          the non -1 values
        """
        shortest = {"red": [0] + [-1 for _ in range(n-1)],
                    "blue": [0] + [-1 for _ in range(n-1)]}
        edges = {"red":  [[] for _ in range(n)],
                "blue":  [[] for _ in range(n)]}
                
        for edge in redEdges:
            edges['red'][edge[0]].append(edge[1])
        for edge in blueEdges:
            edges['blue'][edge[0]].append(edge[1])
        
        queue = deque([(0, "red"), (0, "blue")])
        while queue:
            node, colour = queue[0]
            opp_colour = "blue" if colour == "red" else "red"
            queue.popleft()

            dist = shortest[colour][node]
            for edge in edges[colour][node]:
                if shortest[opp_colour][edge] == -1:
                    shortest[opp_colour][edge] = dist+1
                    queue.append((edge, opp_colour))

        output = []
        for i in range(n):
            if shortest['red'][i] == -1 or shortest['blue'][i] == -1:
                output.append(max(shortest['red'][i], shortest['blue'][i]))
            else:
                output.append(min(shortest['red'][i], shortest['blue'][i]))

        return output
