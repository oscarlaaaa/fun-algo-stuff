from typing import *

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

## 2022-10-31 (two records; a bit confusing)
class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        """

        input: linked list head of length n
        output: deep copy of the linked list

        approach:
        - all values should be the same
        - next points to the next node in the list
        - random points to a random node in the list

        - issues lies in that we can have duplicated nodes vals, so we can't tell which
          node a random is pointing to unless we traverse thru a bit?
        
        - record down the list in a dictionary with nodes being the keys and indices being the values
        - record down a new list with whatever each random is pointing to
        """

        record = dict()   # k = node, v = idx
        new_list = []
        i, cur = 0, head
        while cur:
            new_list.append(Node(cur.val))
            if len(new_list) >= 2:
                new_list[-2].next = new_list[-1]

            record[(cur)] = i
            i += 1
            cur = cur.next
        
        for node, idx in record.items():
            if node.random:
                new_list[idx].random = new_list[record[(node.random)]]
        
        return new_list[0] if new_list else None

## 2022-10-31 (more optimized with dictionary)
class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        """
        approach 2:
        - create dict with old nodes as keys, and new nodes as vals
        - for each node:
            - if old node has a random or next, then assign new node to the val of dict[oldnode.random or next]
        - return dict[head]
        """
        record = dict()   # k = orig node, v = new node
        cur = head
        while cur:
            record[cur] = Node(cur.val)
            cur = cur.next
        
        for node, new_node in record.items():
            if node.next:
                new_node.next = record[node.next]

            if node.random:
                new_node.random = record[node.random]
                
        return record[head] if head in record else None
        