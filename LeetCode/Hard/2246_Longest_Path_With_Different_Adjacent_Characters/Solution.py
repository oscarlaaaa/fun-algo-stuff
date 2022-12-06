from typing import *

## 2022-04-18 (first attempt using DFS-focused approach with memoization and custom class)
class Node:
    def __init__(self, val):
        self.neighbours = set()
        self.val = val
        self.memo = dict()
    
    def __str__(self):
        return f"val: {self.val}"
class Solution:
    def findLongestPath(self, node, seen):
        if not node:
            return 0
        
        longest = 1
        seen.add(node)
        for neighbour in node.neighbours:
            if neighbour not in seen and neighbour.val != node.val:
                if neighbour in node.memo:
                    longest = max(longest, node.memo[neighbour])
                else:
                    path = 1 + self.findLongestPath(neighbour, seen)
                    node.memo[neighbour] = path
                    longest = max(longest, path)
        return longest
        
    def longestPath(self, parent: List[int], s: str) -> int:
        nodes = [Node(s[i]) for i in range(len(parent))]
        
        for i, p in enumerate(parent):
            if p != -1:
                nodes[i].neighbours.add(nodes[p])
                nodes[p].neighbours.add(nodes[i])
        
        longest = 0
        for node in nodes:
            longest = max(longest, self.findLongestPath(node, set()))
            
        return longest

## 2022-04-18 (better attempt where paths aren't traversed multiple times; better designed Node class)
class Node:
    def __init__(self, val):
        self.children = []
        self.val = val
    
    def __str__(self):
        return f"val: {self.val}"
class Solution:
    longest = 1
    def findLongestPath(self, node):
        if not node:
            return 0
        
        disconnected = [] # longest paths where node.val == child.val
        connected = []    # longest paths where node.val != child.val
        
        for child in node.children:
            if child.val == node.val:
                disconnected.append(self.findLongestPath(child))
            else:
                connected.append(self.findLongestPath(child))
        
        disc = max(disconnected) if disconnected else 1
        conn = 1 + max(connected) if connected else 1
        self.longest = max(max(disc, conn), self.longest)

        # if we have multiple in connected (multiple children where node.val != child.val)
        # then we can connect the two greatest paths into 1 long path
        if len(connected) >= 2:
            connected = sorted(connected)
            self.longest = max(self.longest, connected[-1] + 1 + connected[-2])
        
        return conn
        
    def longestPath(self, parent: List[int], s: str) -> int:
        nodes = [Node(s[i]) for i in range(len(parent))]
        
        for i, p in enumerate(parent):
            if p != -1:
                nodes[p].children.append(nodes[i])
        
        self.findLongestPath(nodes[0])
        return self.longest

## 2022-04-18 (cleaned-up, sexier version of above with some dank list comp and without custom class)
class Solution:
    longest = 1
    def findLongestPath(self, node, parent, children, s):
        disconnected = [self.findLongestPath(child,parent, children, s) \
                        for child in children[node] if s[child] == s[node]]
        connected = [self.findLongestPath(child,parent, children, s) \
                     for child in children[node] if s[child] != s[node]]
        
        disc = max(disconnected) if disconnected else 1
        conn = 1 + max(connected) if connected else 1
        self.longest = max(max(disc, conn), self.longest)
        if len(connected) >= 2:
            connected = sorted(connected)
            self.longest = max(self.longest, connected[-1] + 1 + connected[-2])
        
        return conn
        
    def longestPath(self, parent: List[int], s: str) -> int:
        children = [[] for _ in range(len(parent))]
        
        for i, p in enumerate(parent):
            if p != -1:
                children[p].append(i)
        
        self.findLongestPath(0, parent, children, s) ## start at top to bubble downwards
        return self.longest