from typing import *
from heapq import *

## 2022-10-22 (heap + custom inverse string comparator)
class Solution:
    class InverseString:
        """
        Serves to reverse the string's usual comparator
        (ex. 'a' is now after 'aa', 'a' is after 'b')
        """
        def __init__(self, word):
            self.word = word
        def __lt__(self, other):
            return self.word > other.word
        def __eq__(self, other):
            return self.word == other.word
        def __str__(self):
            return self.word

    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counts = dict()
        for word in words:
            counts[word] = counts[word]+1 if word in counts else 1
        
        x = [(count, Solution.InverseString(word)) for word, count in counts.items()]

        heap = []
        for word in x:
            heappush(heap, word)
            if len(heap) > k:
                heappop(heap)

        return [str(x[1]) for x in reversed(sorted(heap))]
