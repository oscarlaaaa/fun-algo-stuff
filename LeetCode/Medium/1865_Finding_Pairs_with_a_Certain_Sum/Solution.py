## 2025-07-06 - twosum-style approach
class FindSumPairs:
    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = nums1
        self.nums2 = nums2

        self.nums1Counts = dict()
        self.nums2Counts = dict()
        for num in nums1:
            self.nums1Counts[num] = self.nums1Counts.get(num, 0) + 1

        for num in nums2:
            self.nums2Counts[num] = self.nums2Counts.get(num, 0) + 1
        

    def add(self, index: int, val: int) -> None:
        """
        Adds a positive integer to an element in nums2
        """
        oldNum = self.nums2[index]
        newNum = self.nums2[index] + val
        
        self.nums2Counts[oldNum] -= 1
        if self.nums2Counts[oldNum] == 0:
            del self.nums2Counts[oldNum]
        
        self.nums2[index] += val
        self.nums2Counts[newNum] = self.nums2Counts.get(newNum, 0) + 1

    def count(self, tot: int) -> int:
        """
        Counts the number of pairs where nums1[i] + nums2[j] equals total
        """
        pairs = 0
        for num in self.nums1Counts:
            neededNum = tot - num
            if neededNum < 1 or neededNum not in self.nums2Counts:
                continue

            pairs += self.nums1Counts[num] * self.nums2Counts.get(neededNum, 0)
        
        return pairs

# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)