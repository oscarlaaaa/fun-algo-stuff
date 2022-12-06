from typing import *

## 2022-11-04 (memoized DFS)
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        """
        input: num of courses to take, and 2d list of prereqs [x, y] x requires y
        output: whether we can finish the 2 courses required

        - the only time we are unable to finish a course is if we have a circular dependency

        approach:
        - map out the prereqs as an adjacency list
            - node neighbours = its prereqs
        - traverse through using DFS all neighbours (prereqs) of a node, and mark it as complete after
        - we can skip nodes we've already ran through without issue because every node in a cycle 
            would lead to a cycle, so if we don't find a cycle that means its not part of one
        - if we encounter a cycle (keep track using a set at each start), then return false
        - use memo to prevent duplication of work
        """
        def DFS(node, adj_list, seen, memo):
            if node in memo:
                return memo[node]

            seen.add(node)
            has_loop = False
            for neighbour in adj_list[node]:
                if neighbour in seen:
                    has_loop = True
                    break
                has_loop = has_loop or DFS(neighbour, adj_list, seen, memo)
            seen.remove(node)
            memo[node] = has_loop
            return has_loop

        adj_list = [[] for _ in range(numCourses)]
        for course, prereq in prerequisites:
            adj_list[course].append(prereq)     
        
        memo = dict()
        for i in range(numCourses):
            if i not in memo and DFS(i, adj_list, set(), memo):
                return False
        return True
