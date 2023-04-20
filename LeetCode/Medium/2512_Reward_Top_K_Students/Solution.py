## 2023-04-19 (priority queue)
import heapq
class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        n = len(report)
        values = {word: 3 for word in positive_feedback} | {word: -1 for word in negative_feedback}
        heap = []
        
        for i in range(n):
            score = 0
            for token in report[i].split(" "):
                score += values.get(token, 0)
            
            # min heap, so top of the heap will have the lowest score + the highest id (as we inverted id)
            heapq.heappush(heap, (score, -student_id[i]))
            if len(heap) > k: # because we never go above k size, push/pop will be max time complexity of O(logk)
                heapq.heappop(heap)
        
        output = []
        while heap:
            output.append(-heap[0][1])
            heapq.heappop(heap)

        # return reversed as popping onto our output will be ordered min->max when we want max->min
        return reversed(output)