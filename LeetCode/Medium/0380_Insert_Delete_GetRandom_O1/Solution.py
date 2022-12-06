## 2022-11-28
import random
class RandomizedSet:
    """
    - utilize a list, and a map
        - set to check for existence + hold index
        - list to grab random values from
    - both keep track of currently held values
    - holds a "element_size" variable
        - insert increases by 1, remove decreases
        - represents next "empty" index in the list
    
    insert:
    - inserts value into the set with element_size as index
    - if element_size >= list size, insert empty val into list
    - replaces list[element_size] with value
    - increment element_size

    delete:
    - decrement element_size
    - deletes value from set
    - swap element at list[element_size] with deleted val in list if there are other elements

    random:
    - math.random int between 0 and element_size (exclusive)
    - return element at that index
    """

    def __init__(self):
        self._indices = dict()
        self._elements = []
        self._element_size = 0
        
    def insert(self, val: int) -> bool:
        if val in self._indices:
            return False
        if self._element_size >= len(self._elements):
            self._elements.append(-1)

        self._indices[val] = self._element_size
        self._elements[self._element_size] = val
        self._element_size += 1

        return True
        
    def remove(self, val: int) -> bool:
        if val not in self._indices:
            return False
        
        remove_idx = self._indices[val]
        del self._indices[val]
        self._element_size -= 1
        
        ## swap removed element to the end if we have other elements to swap it with
        if self._element_size != remove_idx:
            self._indices[self._elements[self._element_size]] = remove_idx
            self._elements[remove_idx] = self._elements[self._element_size]

        return True
        
    def getRandom(self) -> int:
        return self._elements[random.randint(0, self._element_size-1)]
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()