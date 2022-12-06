from typing import *

## 2022-11-02 (DFS)
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        """
        inputs: start = starting gene string
                end = target gene string
                bank = valid steps in between
        output: num of mutations to go from start to end

        - one gene can only mutate into another if the difference is 1 gene
        - start is assumed to be valid, but end might not?

        approach
        - adjacency list 
        - each gene is neighbors with other genes that are 1 mutation away
        - want to get from x to y
        """  
        bank.append(start)
        mutations = { gene: [] for gene in bank }
        for gene1 in bank:
            for gene2 in bank:
                if gene1 == gene2:
                    continue
                if sum([gene1[i] != gene2[i] for i in range(8)]) == 1:
                    mutations[gene1].append(gene2)
            
        def DFS(node, end, mutations, seen):
            if node == end:
                return 0
            if node in seen:
                return -1
                     
            mutations_to_end = -1   
            seen.add(node)
            for neighbor in mutations[node]:
                search = DFS(neighbor, end, mutations, seen)
                if search == -1:
                    continue
                mutations_to_end = min(mutations_to_end, 1 + search) if mutations_to_end != -1 else 1 + search
            seen.remove(node)
            return mutations_to_end

        return DFS(start, end, mutations, set())

## 2022-11-02 (BFS, more efficient since it has an early exit condition)
from collections import deque
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        bank.append(start)
        mutations = { gene: [] for gene in bank }
        for i in range(len(bank)-1):
            for j in range(i+1, len(bank)):
                if sum([bank[i][x] != bank[j][x] for x in range(8)]) == 1:
                    mutations[bank[i]].append(bank[j])
                    mutations[bank[j]].append(bank[i])
                
        seen = set()
        queue = deque([(start, 0)])
        while queue:
            node, steps = queue.popleft()
            if node == end:
                return steps
            seen.add(node)
            for neighbour in mutations[node]:
                if neighbour not in seen:
                    queue.append((neighbour, steps+1))
        return -1
