## 2023-02-19 (double linked list)
class LRUCache:
    """
    notes:
    - initialize a cache that holds a set capacity of keys/vals, and removes the
      least recently used value if we will exceed the capacity
    - probably using a doubly-linked list
        - whenever a key is used, we can move it to the back of our deque by disconnecting
          it and connecting the nodes around it together, then putting the node at the back
        - if we need to boot one, the node at the front gets the boot
    
    analysis:
    - time = O(1) amortized for all operations
    - space = O(n) where n=capacity of the cache
    """
    class DLL:
        def __init__(self, key, val):
            self.front = None
            self.back = None
            self.key = key
            self.val = val

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.key_nodes = dict()

        self.queue_front = LRUCache.DLL(None, None)
        self.queue_back = LRUCache.DLL(None, None)
        self.queue_front.back = self.queue_back
        self.queue_back.front = self.queue_front

    def __remove_node(self, node):
        node.front.back, node.back.front = node.back, node.front
        del self.key_nodes[node.key]

    def __insert_back(self, node):
        node_front = self.queue_back.front
        node_front.back, node.front = node, node_front
        self.queue_back.front, node.back = node, self.queue_back
    
    def get(self, key: int) -> int:
        if key not in self.key_nodes:
            return -1
        
        node = self.key_nodes[key]
        node.front.back, node.back.front = node.back, node.front
        self.__insert_back(node)
        return node.val
        
    def put(self, key: int, value: int) -> None:
        if key in self.key_nodes:
            self.__remove_node(self.key_nodes[key])
        self.key_nodes[key] = LRUCache.DLL(key, value)
        self.__insert_back(self.key_nodes[key])
        
        # remove the front of the queue if we've exceeded capacity
        if len(self.key_nodes) > self.capacity:
            self.__remove_node(self.queue_front.back)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)